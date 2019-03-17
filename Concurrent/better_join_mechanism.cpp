#include <iostream>
#include "common.h"

void foo()
{
    printf("Hello from foo \n");
}

void other_operations()
{
    std::cout << "This is other operation \n" << std::endl;
    throw std::runtime_error("this is a runtime error");
}

int main(int argc, char* argv[])
{
    std::thread foo_thread(foo);
    thread_guard tg(foo_thread);
    try {
        other_operations();
    }
    catch (...)
    {}

    return 0;
}
