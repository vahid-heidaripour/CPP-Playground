#include <iostream>

using namespace std;

class Base
{
public:
    Base() {}
    //~Base() {}
    virtual ~Base() = default;
};

class Derived : public Base
{
public:
    Derived()
    {
        mString = new char[30];
        cout << "mString allocated" << endl;
    }
    ~Derived()
    {
        delete[] mString;
        cout << "mString deallocated" << endl;
    }

private:
    char* mString;
};

int main()
{
    Base* ptr = new Derived(); //mString is allocating here
    delete ptr; //~Base is called, but not ~Derived because the destructor is not virtual
    // to avoid that ~Base should be virtual

    return 0;
}