from threading import Condition
class FooBar:
    def __init__(self, n):
        self.n = n
        self.c1 = Condition()
        self.f = True

    def foo(self, printFoo: 'Callable[[], None]') -> None:
        for i in range(self.n):
            with self.c1:
                self.c1.wait_for(lambda: self.f)
                printFoo()
                self.f = False
                self.c1.notify(1)

    def bar(self, printBar: 'Callable[[], None]') -> None:
        for i in range(self.n):
            with self.c1:
                self.c1.wait_for(lambda: not self.f)
                printBar()
                self.f = True
                self.c1.notify(1)