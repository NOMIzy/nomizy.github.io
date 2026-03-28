import threading

class Counter:
    def __init__(self):
        self.lock = threading.Lock()
        self.value = 0

    def increment(self):
        with self.lock:
            self.value += 1

counter = Counter()

def worker():
    for _ in range(100000):
        counter.increment()

threads = []
for i in range(10):
    thread = threading.Thread(target=worker)
    threads.append(thread)
    thread.start()

for thread in threads:
    thread.join()#使得所有线程都完成

print("Counter value:", counter.value)#结果是1000000
