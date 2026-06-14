import threading
import time

# 方法1，继承Thread类
class MyThread(threading.Thread):
    def __init__(self, name):
        threading.Thread.__init__(self)
        self.name = name

    def run(self):
        print(f"Starting {self.name}")
        time.sleep(2)
        print(f"Exiting {self.name}")

# 创建线程
thread1 = MyThread("Thread-1")
thread2 = MyThread("Thread-2")

# 启动线程
thread1.start()
thread2.start()

# 等待线程完成
thread1.join()
thread2.join()

print("Exiting Main Thread")

#方法2，创建Thread对象
def print_time(threadName, delay):
    print(f"Starting {threadName}")
    time.sleep(delay)
    print(f"Exiting {threadName}")

# 创建线程
thread1 = threading.Thread(target=print_time, args=("Thread-1", 2))
thread2 = threading.Thread(target=print_time, args=("Thread-2", 4))

# 启动线程
thread1.start()
thread2.start()

# 等待线程完成
thread1.join()
thread2.join()

print("Exiting Main Thread")