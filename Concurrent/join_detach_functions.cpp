#include <iostream>
#include <thread>
#include <chrono>

void foo()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    printf("Hello from foo \n");
}

void bar()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    printf("Hello from bar \n");
}

int main(int argc, char* argv[])
{
    std::thread foo_thread(foo);
    std::thread bar_thread(bar);

    bar_thread.detach();
    printf("This is after bar thread detach \n");

    foo_thread.join();
    printf("This is after foo thread join \n");

    return 0;
}
