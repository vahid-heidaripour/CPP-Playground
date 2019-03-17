#ifndef CONCURRENT_COMMON_H
#define CONCURRENT_COMMON_H

#include <thread>

class thread_guard
{
    std::thread &t;

public:
    explicit thread_guard(std::thread & _t) : t(_t)
    {

    }

    ~thread_guard()
    {
        if (t.joinable())
            t.join();
    }

    thread_guard(thread_guard &const) = delete;
    thread_guard &operator= (thread_guard &const) = delete;
};

#endif