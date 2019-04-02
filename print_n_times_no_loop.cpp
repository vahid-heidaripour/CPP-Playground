// How to print something n time without loop or recursion?
// using arrays and constructors

#include <iostream>
using namespace std;

class Base
{
public:
    Base() { cout << "Hello World!" << endl; }
};

int main()
{
    const int N = 10;
    Base b[N];

    return 0;
}
