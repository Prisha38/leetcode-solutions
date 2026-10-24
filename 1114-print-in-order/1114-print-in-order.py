from threading import Semaphore
class Foo:
    def __init__(self):
        self.s1 = Semaphore(1)
        self.s2 = Semaphore(1)
        self.s1.acquire()
        self.s2.acquire()

    def first(self, printFirst: 'Callable[[], None]') -> None:
        printFirst()
        self.s1.release()

    def second(self, printSecond: 'Callable[[], None]') -> None:
        with self.s1:
            printSecond()
            self.s2.release()

    def third(self, printThird: 'Callable[[], None]') -> None:
        with self.s2:
            printThird()