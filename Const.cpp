#include <cstdlib>

const double PI = 3.141592653589793238462;

void func(const int /*param*/)
{
    // not allowed to change param...
}

void constIntOne()
{
    const int* ip;
    ip = new int[10];
    //ip[4] = 10; // does not compile
}

void constIntTwo()
{
    int const* ip;
    ip = new int[10];
    //ip[4] = 10; // does not compile
}

void constPtrOne()
{
    int* const ip = nullptr;
    //ip = new int[10]; // does not compile
    //ip[4] = 10; // Error: dereferencing a null pointer
}

void constPtrTwo()
{
    int* const ip = new int[10];
    ip[4] = 10;
}

void constIntPtrOne()
{
    int const* const ip = nullptr;
}

void constIntPtrTwo()
{
    const int* const ip = nullptr;
}

void manyLevelConst()
{
    const int * const * const * const ip = nullptr;
}

class BigClass;
void doSomething(const BigClass& /*arg*/)
{

}

int main()
{
    int* ip;
    ip = new int[10];
    ip[4] = 10;

    int z;
    const int& zRef = z;
    // zRef = 4; // does not compile

    return 0;
}