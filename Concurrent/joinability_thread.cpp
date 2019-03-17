#include <iostream>
#include <thread>

void foo()
{
    printf("Hello from foo \n");
}

int main(int argc, char* argv[]) {
    std::thread thread1(foo);

    if (thread1.joinable()) {
        printf("Thread 1 is joinable before join \n");
    } else
    {
        printf("Thread 1 is not joinable before join \n");
    }

    thread1.join();

    if (thread1.joinable()) {
        printf("Thread 1 is joinable before join \n");
    } else
    {
        printf("Thread 1 is not joinable before join \n");
    }

    return 0;
}