#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct delete_ptr 
{
    template <typename T>
    void operator () (T p)
    {
        delete p;
    }
};

class Base
{
public:
    Base() { cout << "Base\n"; }
    virtual ~Base() { cout << "~Base\n"; }
    virtual void print() = 0;
};

class A : public Base
{
    string value;

public:
    A(string value) : value{value} { cout << "A\n"; }
    ~A() { cout << "~A\n"; }

    void print() { cout << value << endl; }
};

class B : public Base
{
    int value;

public:
    B(int value) : value{value} { cout << "B\n"; }
    ~B() { cout << "~B\n"; }

    void print() { cout << value << endl; }
};

int main()
{
    vector<Base*> vec;
    vec.emplace_back(new A("test"));
    vec.emplace_back(new B(12));

    for_each(vec.begin(), vec.end(), delete_ptr());
    vec.clear();

    return 0;
}