from threading import Event
class Foo: 
    def __init__(self):
        self.e1 = Event()
        self.e2 = Event()

    def first(self, printFirst: 'Callable[[], None]') -> None:
        printFirst()
        self.e1.set()

    def second(self, printSecond: 'Callable[[], None]') -> None:
        self.e1.wait()
        printSecond()
        self.e2.set()

    def third(self, printThird: 'Callable[[], None]') -> None:
        self.e2.wait()
        printThird()   