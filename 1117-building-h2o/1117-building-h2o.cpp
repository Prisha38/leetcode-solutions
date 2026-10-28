class H2O {
private:
    std::mutex mtx;
    std::condition_variable cv;
    int h_count;

public:
    H2O() : h_count(0) {}

    void hydrogen(function<void()> releaseHydrogen) {
        std::unique_lock<std::mutex> lock(mtx);
        
        // Wait until fewer than 2 Hydrogens have been released
        cv.wait(lock, [this]() {
            return h_count < 2;
        });

        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        h_count++;
        
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        std::unique_lock<std::mutex> lock(mtx);
        
        // Wait until both Hydrogens have been released
        cv.wait(lock, [this]() {
            return h_count == 2;
        });

        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        h_count = 0;
        
        cv.notify_all();
    }
};