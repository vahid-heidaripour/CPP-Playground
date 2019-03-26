#include <iostream>
#include <thread>
#include <atomic>

int main(int argc, char* arg[])
{
    std::atomic<bool> flag_1;
    std::cout << "flag 1 = " << flag_1 << std::endl;

    // cannot copy construct
    //std::atomic<bool> flag_2(flag_1);

    // cannot copy assignable
    //std::atomic<bool> flag_3 = flag_1;

    // construct using non atomic boolean value
    bool non_atomic_bool = true;
    std::atomic<bool> flag_4(non_atomic_bool);
    std::cout << "flag 4 = " << flag_4 << std::endl;

    // initialize with non atomic boolean value
    std::atomic<bool> flag_5{non_atomic_bool};
    std::cout << "flag 5 = " << flag_5 << std::endl;

    // copying variable of type 'std::atomic<bool>' invokes deleted constructor
    //std::atomic<bool> flag_6 = non_atomic_bool;

    return 0;
}
