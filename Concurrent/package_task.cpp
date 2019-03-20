#include <iostream>
#include <future>
#include <numeric>
#include <thread>
#include <functional>

int add(int x, int y)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "add function runs in : " << std::this_thread::get_id() << std::endl;
    return x + y;
}

void task_thread()
{
    std::packaged_task<int(int, int)> task_1(add);
    std::future<int> future_1 = task_1.get_future();

    std::thread thread_1(std::move(task_1), 5, 6);
    thread_1.detach();

    std::cout << "task thread - " << future_1.get() << std::endl;
}

void task_normal()
{
    std::packaged_task<int(int, int)> task_1(add);
    std::future<int> future_1 = task_1.get_future();
    task_1(1, 8);
    std::cout << "task normal - " << future_1.get() << std::endl;
}

int main(int argc, char* argv[])
{
    task_thread();
    task_normal();
    return 0;
}