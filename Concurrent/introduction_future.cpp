#include <iostream>
#include <future>

int some_operation_calculations()
{
    return 5000;
}

void do_other_calculations()
{
    std::cout << "Doing other stuff " << std::endl;
}

int main(int argc, char* argv[])
{
    std::future<int> the_future = std::async(some_operation_calculations);
    do_other_calculations();
    std::cout << "The answer for calculations is " << the_future.get() << std::endl;

    return 0;
}