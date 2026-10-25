from threading import Condition, Barrier
class FooBar: 
    def __init__(self, n):
        self.n = n
        self.br = Barrier(2)
        self.c = Condition()
        self.f = False

    def foo(self, printFoo: 'Callable[[], None]') -> None:
        for i in range(self.n):
            with self.c:
                printFoo()
                self.f = True
                self.c.notify_all()
            self.br.wait()

    def bar(self, printBar: 'Callable[[], None]') -> None:
        for i in range(self.n):
            with self.c:
                self.c.wait_for(lambda: self.f)
                printBar()            
                self.f = False
            self.br.wait()