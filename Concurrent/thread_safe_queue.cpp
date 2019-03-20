#include <iostream>
#include <mutex>
#include <queue>
#include <memory>
#include <condition_variable>
#include <thread>

template <typename T>
class thread_safe_queue
{
    std::mutex m;
    std::condition_variable cv;
    std::queue<std::shared_ptr<T>> queue;

public:
    thread_safe_queue() {}
    thread_safe_queue(thread_safe_queue const& other_queue)
    {

    }

    void push(T& value)
    {
        std::lock_guard<std::mutex> lg(m);
        queue.push(std::make_shared<T>(value));
        cv.notify_one();
    }

    std::shared_ptr<T> pop()
    {

    }

    bool empty()
    {

    }

    std::shared_ptr<T> wait_pop()
    {

    }

    size_t size()
    {

    }
};