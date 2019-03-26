#include <iostream>
#include <thread>
#include <atomic>

int main(int argc, char* argv[])
{
    std::atomic_flag flag = ATOMIC_FLAG_INIT;

    std::cout << "1. previews flag value : " << flag.test_and_set() << std::endl;
    std::cout << "2. previews flag value : " << flag.test_and_set() << std::endl;

    flag.clear();

    std::cout << "3. previews flag value : " << flag.test_and_set() << std::endl;

    return 0;
}