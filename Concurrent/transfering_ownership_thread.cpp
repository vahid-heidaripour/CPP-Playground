#include <iostream>
#include <thread>
#include <chrono>

void foo()
{
    printf("Hello from foo \n");
}

int main(int argc, char* argv[])
{
    std::thread thread_1(foo);

    std::thread thread_2 = std::move(thread_1);

    thread_1.join(); //terminating with uncaught exception
    thread_2.join();

    return 0;
}