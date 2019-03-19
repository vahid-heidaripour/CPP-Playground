#include <iostream>
#include <mutex>
#include <stack>
#include <thread>

template <typename T>
class thread_safe_stack
{
    std::stack<T> stk;
    std::mutex m;

    void push(T element)
    {

    }

    void pop()
    {

    }

    bool empty()
    {

    }

    size_t size()
    {

    }
};

int main(int argc, char* argv[])
{
    return 0;
}