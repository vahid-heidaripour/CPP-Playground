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

class B : public A
{
public:
    int _b;
};

class C : public A
{
public:
    int _c;
};

class D : public B, public C
{
public:
    int _d;
};

int main()
{
    return 0;
}