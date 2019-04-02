#include <iostream>
using namespace std;

//      A
//     / \
//    B   C
//     \ /
//      D


class A
{
public:
    int _a;
};

// A object memory layout
// _a

class B : virtual public A
{
public:
    int _b;
};

// B object memory layout
// _b, _a
// size of B is sizeof(_b) + sizeof(_a)

class C : virtual public A
{
public:
    int _c;
};

// C object memory layout
// _c, _a
// size of C is sizeof(_c) + sizeof(_a)

class D : public B, public C
{
public:
    int _d;
};

// D object memory layout
// _a, _b, _c, _a, _d

int main()
{
    D d; // no problem
    d._b = 10; // OK
    d._c = 10; // OK
    d._d = 10; // OK
    d._a = 10; // here is the ambiguity problem, to solve it we need to inherent from A virtually
    return 0;
}