/* How to have a pure base class and a vector of it with its derived classes object.
 * If you want to use raw pointer instead of unique_ptr, make sure that you released 
 * the memory at the end of main.
 * Make sure about virtual destructor in base class. 
 */

#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Base
{
public:
    Base() { cout << "Base\n"; }
    virtual ~Base() { cout << "~Base\n"; }
    virtual void print() const = 0;
};

class A : public Base
{
    string value;
public:
    A(string value) : value{value} { cout << "A\n"; }
    ~A() { cout << "~A\n"; }
    void print() const { cout << value << endl; } 
};

class B : public Base
{
    int value;
public:
    B(int value) : value{value} { cout << "B\n"; }
    ~B() { cout << "~B\n"; }
    void print() const { cout << value << endl; }
};

int main()
{
    vector<unique_ptr<Base>> vec;
    vec.push_back(make_unique<A>("test"));
    vec.push_back(make_unique<B>(12));
    for (const auto& v : vec)
	    v->print();
    return 0;
}
