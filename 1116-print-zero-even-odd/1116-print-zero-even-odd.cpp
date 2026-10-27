class ZeroEvenOdd {
private:
    int n;
    mutex m;
    condition_variable cv;
    int turn;
    int i;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        this->turn=0;
        this->i=1;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        unique_lock<mutex>lock(m);
        while(i<=n){
          while(i<=n && turn!=0) cv.wait(lock);
          if(i<=n)printNumber(0);
          turn=(i%2==0)?1:2;
          cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        unique_lock<mutex>lock(m);
        while(i<=n){
            while(i<=n && turn!=1) cv.wait(lock);
            if(i<=n)printNumber(i);
            turn=0;
            i++;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        unique_lock<mutex>lock(m);
        while(i<=n){
            while(i<=n && turn!=2) cv.wait(lock);
            if(i<=n)printNumber(i);
            turn=0;
            i++;
            cv.notify_all();
        }
    }
};