from threading import Event, Barrier
class FooBar:
    def __init__(self, n):
        self.n = n
        self.br = Barrier(2)
        self.e = Event()

    def foo(self, printFoo: 'Callable[[], None]') -> None:
        for i in range(self.n):
            printFoo()
            self.e.set()
            self.br.wait()

    def bar(self, printBar: 'Callable[[], None]') -> None:
        for i in range(self.n):
            self.e.wait()
            printBar()
            self.e.clear()
            self.br.wait()