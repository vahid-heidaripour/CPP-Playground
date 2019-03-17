#include <iostream>
#include <thread>

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
    try {
        other_operations();
        foo_thread.join();
    }
    catch (...) {
        foo_thread.join();
    }



    return 0;
}
