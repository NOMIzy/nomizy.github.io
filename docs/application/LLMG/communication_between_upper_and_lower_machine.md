# 上位机与下位机间的通信实现


## 基本概念

上位机和下位机的概念常出现在嵌入式领域，但并不仅限于嵌入式领域，它同样适用于其他分布式计算系统中的不同层次和角色的设备。上位机和下位机的划分主要是根据其在分布式系统中的角色和功能来决定的。

**上位机**

（英文：PC/Host Computer、Master Computer 或 Upper Computer）是指控制和协调整个系统的计算机或设备。它通常运行着高级应用程序，并负责处理和管理数据、与用户交互以及与下位机通信，可用于控制或监视另一台或多台下位机。上位机可以是桌面计算机、服务器或其他高级计算设备。

**下位机**

（英文：Peripheral Device、Slave Computer 或 Lower Computer）是指与上位机连接的终端设备（如传感器、执行器、控制器等）。它通常负责执行具体的硬件操作和数据处理任务，如传感器数据采集、控制指令的执行等。下位机可以是微控制器、传感器、执行器或其他低级计算设备。

与下位机相比，上位机通常具有更强大的计算和处理能力，并且能够处理和分析从下位机中获取的数据，实现更高级、更智能的应用。例如在工业自动化应用中，通过上位机实现包括工业控制、机器人控制、实验室测量、过程监控，以及高级的数据分析和可视化等功能，帮助用户更好地理解下位机数据并作出更明智的决策。

**分布式系统**

（英文 Distributed System）这是一个或许有些相近的概念，选取MIT6.824对这个概念的解释。

当人们确实需要：
- 并行性 
- 容错性 Fault Tolerance
 - 可用 availability
 - 可恢复 Recoverability
- 多台物理实体
- 安全性security /孤立性 isolated
- 高性能 performance
的时候，才不得不去设计并实现一个分布式系统，这会有许多挑战：
- 系统部分的故障
- 通讯的故障
- 数据一致性 Consistency
一般的，被连接起来的是许多计算机，用来构建大型的网站服务。
现有的理论与实践聚焦于：
- 存储
- 通信
- 计算
常用的实践包括：
- RPC（[原理参考](https://bbs.huaweicloud.com/blogs/337073）)
- Threads
- Concurrency
- 非易失性存储
- 副本管理



## 通讯过程
上位机和下位机之间通过通信接口或协议进行数据交换和控制信息传递。上位机指示下位机执行特定任务，并接收下位机返回的数据或状态信息。上位机和下位机的合作使得整个系统可以实现复杂的功能和任务。

至于具体如何通讯，一般取决于下位机提供的通讯接口，比如 RS-232、RS-485、以太网、USB，或者是 WiFi、蓝牙之类的无线通信方式。除了通讯接口，下位机还需要具有可靠的、可扩展的通讯协议，比如 Modbus、CAN 等。具体到不同行业，例如仪器仪表、工业控制、汽车行业等，还可能会有特定的标准协议。

## 需求
本次需要为我的机器人任务规划系统完成上位机-下位机的通讯框架，上位机和下位机都可能有多个，我需要实现多对多的通讯，保证信息可靠到达，支持配置多种通讯协议，并且预留大数据量，高实时性的拓展可能。

最早简单使用课内的socket通信构建了一个可以配置多对多的异步通信：
~~~py
#server.py

import asyncio
import json
import struct
import logging

logging.basicConfig(level=logging.INFO)

class ExecutorCommunicationServer:
    def __init__(self, id, ip_address='192.168.43.217', port_num=12345):
        self.id = id
        self.info_queue = asyncio.Queue(30)
        self.clients = []
        self.ip_address = ip_address
        self.port_num = port_num

    def add_info(self, json_data):
        self.info_queue.put_nowait(json_data)

    async def broadcast_message(self, message):
        message_length = len(message)
        for writer in self.clients:
            writer.write(struct.pack("!I", message_length))
            writer.write(message.encode())
        await asyncio.gather(*(writer.drain() for writer in self.clients))

    async def handle_client(self, reader, writer):
        client_address = writer.get_extra_info('peername')
        self.clients.append(writer)
        logging.info(f"New client connected from {client_address}")

        try:
            while True:
                if not self.info_queue.empty():
                    json_content = await self.info_queue.get()
                else:
                    # 队列为空，发送心跳包
                    json_content = json.dumps({"type": -1})

                await self.broadcast_message(json_content)
                logging.info(f"Message sent to all clients.")

                data = await reader.read(1024)  # 等待客户端确认信息
                if not data:
                    break

                reply = data.decode()
                confirmation = json.loads(reply)
                if confirmation.get("status_code") == 1:
                    logging.info("Execution succeeded")
                else:
                    logging.info("Execution error")

                if self.info_queue.empty():
                    await asyncio.sleep(3)
        except Exception as e:
            logging.error(f"Error: {e}")
        finally:
            self.clients.remove(writer)
            writer.close()
            await writer.wait_closed()
            logging.info(f"Client {client_address} disconnected")

    async def start_server(self):
        server = await asyncio.start_server(self.handle_client, self.ip_address, self.port_num)
        async with server:
            logging.info(f"Server listening on {self.ip_address}:{self.port_num}")
            await server.serve_forever()

if __name__ == "__main__":
    server = ExecutorCommunicationServer(id=1)
    asyncio.run(server.start_server())

~~~
~~~py
#client.py
import asyncio
import json
import struct

async def receive_message(reader):
    while True:
        # 接收消息长度
        length_data = await reader.read(4)
        if not length_data:
            break
        
        message_length = struct.unpack("!I", length_data)[0]
        # 接收实际消息
        message_data = await reader.read(message_length)
        if not message_data:
            break

        message = message_data.decode()
        print(f"Received message: {message}")

        # 发送确认信息
        reply = json.dumps({"status_code": 1})
        writer.write(reply.encode())
        await writer.drain()

async def main(ip_address, port_num):
    reader, writer = await asyncio.open_connection(ip_address, port_num)
    print(f"Connected to server at {ip_address}:{port_num}")

    try:
        await receive_message(reader)
    except Exception as e:
        print(f"Error: {e}")
    finally:
        writer.close()
        await writer.wait_closed()
        print("Disconnected from server")

if __name__ == "__main__":
    ip_address = '192.168.43.217'
    port_num = 12345
    asyncio.run(main(ip_address, port_num))

~~~
认识到了需要有较好的容错，拓展，有必要对前人成熟代码做一个学习，找到了ROS的通信部分 https://github.com/ros/ros_comm
具体分析在另一篇[]()

