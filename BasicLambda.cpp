#include <iostream>

using namespace std;

int main()
{
    auto basicLambda = []{ cout << "Hello from Lambda." << endl; };
    basicLambda();

    auto parametersLambda = [](int value){ cout << "The value is: " << value << endl; };
    parametersLambda(23);

    auto returningLambda = [](int a, int b) -> int { return a + b; };
    cout << "The result is: " << returningLambda(12, 34) << endl;

    auto returningLambda2 = [](int a, int b) { return a + b; };
    cout << "The result is: " << returningLambda2(12, 3);

    double data = 1.23;
    auto capturingValue = [data]{ cout << "Data= " << data << endl; };
    capturingValue();

    auto capturingValue2 = [data]() mutable { data *= 2; cout << "Data= " << data << endl; };
    capturingValue2();

    auto capturingRLambda = [&data]{ data *= 2; };
    capturingRLambda();
    cout << "Data= " << data << endl;

    return 0;
}