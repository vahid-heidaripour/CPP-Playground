#include <chrono>
#include "base.h"

int main(int argc, char* argv[])
{
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

    int seqOrCon = atoi(argv[1]);

    std::cout << "List values before operations:" << std::endl;
    Base base;

    switch (seqOrCon)
    {
        case 0:
        {
            std::cout << "\n\nSequential Operations:" << std::endl;
            base.doSequentially();
            break;
        }
        case 1:
        {
            std::cout << "\n\nConcurrent Operations:" << std::endl;
            base.doConcurrently();
            break;
        }
        default:
            break;
    }

    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double> >(end - start);
    std::cout << "Time: " << time_span.count() << " seconds." << std::endl;

    std::cout << "List values after operations:" << std::endl;
    base.printList();

    return 0;
}