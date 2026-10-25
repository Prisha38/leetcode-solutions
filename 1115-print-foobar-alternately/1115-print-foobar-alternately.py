from threading import Lock
class FooBar:
    def __init__(self, n):
        self.n = n
        self.l1 = Lock() # Semaphore(1)
        self.l2 = Lock() # Semaphore(1)
        self.l2.acquire()

    def foo(self, printFoo: 'Callable[[], None]') -> None:
        for i in range(self.n):
            self.l1.acquire()
            printFoo()
            self.l2.release()

    def bar(self, printBar: 'Callable[[], None]') -> None:
        for i in range(self.n):
            self.l2.acquire()
            printBar()
            self.l1.release()