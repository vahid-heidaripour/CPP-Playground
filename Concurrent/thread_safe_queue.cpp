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
    thread_safe_queue(thread_safe_queue const& other_queue) {}

    void push(T& value)
    {
        std::lock_guard<std::mutex> lg(m);
        queue.push(std::make_shared<T>(value));
        cv.notify_one();
    }

    std::shared_ptr<T> pop()
    {
        std::lock_guard<std::mutex> lg(m);
        if (queue.empty())
        {
            return std::shared_ptr<T>();
        }
        else
        {
            std::shared_ptr<T> ref(queue.front());
            queue.pop();
            return  ref;
        }
    }

    bool empty()
    {
        std::lock_guard<std::mutex> lg(m);
        return queue.empty();
    }

    std::shared_ptr<T> wait_pop()
    {
        std::unique_lock<std::mutex> lg(m);
        cv.wait(lg, [this] {
            return !queue.empty();
        });
        std::shared_ptr<T> ref = queue.front();
        queue.pop();
        return ref;
    }

    size_t size()
    {
        std::lock_guard<std::mutex> lg(m);
        queue.size();
    }
};

int main(int argc, char* argv[])
{
    return 0;
}