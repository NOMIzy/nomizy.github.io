import threading
import time

class Philosopher(threading.Thread):
    def __init__(self, name, left_fork, right_fork):
        threading.Thread.__init__(self)
        self.name = name
        self.left_fork = left_fork
        self.right_fork = right_fork

    def run(self):
        for i in range(3):
            print(f"{self.name} is thinking.")
            time.sleep(1)
            self.dine()

    def dine(self):
        fork1, fork2 = self.left_fork, self.right_fork
        while True:
            fork1.acquire()
            locked = fork2.acquire(False)
            if locked: break
            fork1.release()
            print(f"{self.name} swaps forks.")
            fork1, fork2 = fork2, fork1
        self.eat()
        fork2.release()
        fork1.release()

    def eat(self):
        print(f"{self.name} starts eating.")
        time.sleep(2)
        print(f"{self.name} finishes eating and leaves to think.")

def main():
    forks = [threading.Lock() for n in range(5)]
    philosopher_names = ['A', 'B', 'C', 'D', 'E']

    philosophers = [Philosopher(philosopher_names[i], forks[i % 5], forks[(i + 1) % 5])
                    for i in range(5)]

    for p in philosophers:
        p.start()

    for p in philosophers:
        p.join()

if __name__ == "__main__":
    main()
