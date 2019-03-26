#include <iostream>
#include <thread>
#include <atomic>

int main(int argc, char* argv[])
{
    std::atomic<int> x(20);

    int expected_value = 20;
    std::cout << "previews expected value - " << expected_value << std::endl;

    // if the expected value is equal to x, it returns true
    bool return_val = x.compare_exchange_weak(expected_value, 6);

    std::cout << "operation successful    - " << (return_val ? "yes" : "no") << std::endl;
    std::cout << "current expected value  - " << expected_value << std::endl;
    std::cout << "current x               - " << x.load() << std::endl;

    return 0;
}