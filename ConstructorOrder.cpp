#include <iostream>

using namespace std;

class Something
{
public:
    Something() { cout << 2 << endl; }
};

class Base
{
public:
    Base() { cout << 1 << endl; }
};

class Derived : public Base
{
public:
    Derived() { cout << 3 << endl; }

private:
    Something mDataMember;
};

int main()
{
    Derived myDerived;

    return 0;
}

/* When the myDerived object is created,
 * the constructor for Base is called first, outputting the 1.
 * Next, mDataMember is initialized, calling the Something constructor, which outputs the 2.
 * Finally, the Derived constructor is called, which outputs 3
 */