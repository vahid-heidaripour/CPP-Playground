#include <iostream>
#include <thread>
#include <atomic>

int main(int argc, char* argv[])
{
    int values[20];

    for (int i = 0; i < 20; i++)
        values[i] = i + 1;

    std::atomic<int*> x_pointer(values);

    std::cout << "atomic integer pointer lock free    ? "
              << (x_pointer.is_lock_free() ? "yes" : "no") << std::endl;

    int* y_pointer = values + 3;

    x_pointer.store(y_pointer);
    std::cout << "value referencing to by pointer     : " << *(x_pointer.load()) << std::endl;

    bool ret_val = x_pointer.compare_exchange_weak(y_pointer, values + 10);
    std::cout << "store operation successful          : " << (ret_val ? "yes" : "no") << std::endl;
    std::cout << "new value pointer by atomic pointer : " << *x_pointer << std::endl;

    return 0;
}