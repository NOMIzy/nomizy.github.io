from concurrent.futures import ThreadPoolExecutor
import time

def worker(name):
    print(f"Starting {name}")
    time.sleep(2)
    print(f"Exiting {name}")

with ThreadPoolExecutor(max_workers=2) as executor:
    futures = [executor.submit(worker, f"Thread-{i}") for i in range(5)]
    
    for future in futures:
        future.result()

print("All threads completed")
