import threading
import queue

def producer(q):
    for i in range(5):
        q.put(i)
        print(f"Produced {i}")

def consumer(q):
    while not q.empty():
        item = q.get()
        print(f"Consumed {item}")

q = queue.Queue()

producer_thread = threading.Thread(target=producer, args=(q,))
consumer_thread = threading.Thread(target=consumer, args=(q,))

producer_thread.start()
producer_thread.join()  # 等待生产者线程完成

consumer_thread.start()
consumer_thread.join()  # 等待消费者线程完成

print("All tasks completed")
