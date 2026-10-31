class DiningPhilosophers {
    const int n{5};
    std::vector<bool> forks;

    std::mutex mx;
    std::condition_variable cv;

public:
    DiningPhilosophers() : forks(n, false) {
        
    }

    void wantsToEat(int id,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork)
    {
        std::unique_lock<std::mutex> lock{mx};
        cv.wait(lock, [&] { return forks[id] == false && forks[(id + 1) % n] == false; });
        forks[id] = forks[(id + 1) % n] = true;
        
        pickLeftFork(); pickRightFork();
        eat();
        putLeftFork(); putRightFork();

        forks[id] = forks[(id + 1) % n] = false;
        cv.notify_all();
    }
};