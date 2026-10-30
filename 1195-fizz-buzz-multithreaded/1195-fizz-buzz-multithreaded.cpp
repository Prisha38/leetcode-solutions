#include<semaphore.h>
class FizzBuzz {
private:
    int n;
    int curr;
    int done;
    
    sem_t mfizz;
    sem_t mbuzz;
    sem_t mfizzbuzz;
    sem_t mnumber;    

public:
    
    FizzBuzz(int n) {
        this->n = n;       
        done=0;
        sem_init(&mfizz,0,0);
        sem_init(&mbuzz,0,0);
        sem_init(&mfizzbuzz,0,0);
        sem_init(&mnumber,0,1);           //number function is our entry point
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while(1)
        {
            sem_wait(&mfizz);             //wait till mfizzbuzz increments mfizz
            if(done) break;
            if(curr%3==0)                
            {
                printFizz();             // print fizz and signal number
                sem_post(&mnumber);
            }
            else {
                sem_post(&mbuzz);        // try other last possibility
            }
        }
        sem_post(&mbuzz);
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while(1)
        {            
            sem_wait(&mbuzz);           // wait till fizz incrementes mbuzz
            if(done) break;
            if(curr%5 == 0)             
            {
                printBuzz();            // print buzz and signal number
                sem_post(&mnumber);
            }
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {     
        while(1)
        {            
            sem_wait(&mfizzbuzz);            //wait till number increases mfizzbuzz
            if(done) break;
            if(curr%3==0 && curr%5==0)
            {                
                printFizzBuzz();             //print fizzbuzz anf signal number 
                sem_post(&mnumber);
            }
            else
            {
                sem_post(&mfizz);            //try other possibility
            }
        }
        sem_post(&mfizz);
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        int i=1;
        while(1)
        {
            sem_wait(&mnumber);
            if(i==n+1)          // break if printed entire rnage
                break;
            if(i%3!=0 && i%5!=0)
            {
                printNumber(i);         //print numbser and rerrun for nexr number
                sem_post(&mnumber);
            }
            else
            {
                curr = i;                
                sem_post(&mfizzbuzz);    //try other possibilities
            }
            i++;
        }
        done = 1;                       // we are done ,
        sem_post(&mfizzbuzz);           // inform other threads to quit
    }
};