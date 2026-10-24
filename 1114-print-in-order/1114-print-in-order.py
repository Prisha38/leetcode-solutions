from threading import Condition
class Foo:
    def __init__(self):
        self.c = Condition()
        self.one = self.two = False


    def first(self, printFirst: 'Callable[[], None]') -> None:
        with self.c: 
            printFirst()
            self.one = True 
            self.c.notify_all()


    def second(self, printSecond: 'Callable[[], None]') -> None:
        with self.c:
            self.c.wait_for(lambda: self.one)
            printSecond()
            self.two = True
            self.c.notify_all()


    def third(self, printThird: 'Callable[[], None]') -> None:
        with self.c:
            self.c.wait_for(lambda: self.two)
            printThird()    