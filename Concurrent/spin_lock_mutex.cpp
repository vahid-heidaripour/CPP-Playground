#include <iostream>
#include <atomic>
#include <memory>
#include <thread>
#include <mutex>

class spinlock_mutex
{
    std::atomic_flag flag = ATOMIC_FLAG_INIT;

public:
    spinlock_mutex()
    {

    }

    void lock()
    {
        while (flag.test_and_set(std::memory_order_acquire));
    }

    void unlock()
    {
        flag.clear(std::memory_order_release);
    }
};

spinlock_mutex mutex;

void func()
{
    std::lock_guard<spinlock_mutex> lg(mutex);
    std::cout << std::this_thread::get_id() << " hello " << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
}

int main(int argc, char* argv[])
{
    std::thread thread_1(func);
    std::thread thread_2(func);

    thread_1.join();
    thread_2.join();

    return 0;
}