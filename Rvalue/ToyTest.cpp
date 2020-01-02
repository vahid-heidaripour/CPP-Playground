#include "Toy.h"

int main()
{
    std::string message1 = "Hello";
    std::string message2 = ", World!";
    Toy t;
    t.handleMessage(message1);
    t.handleMessage(message1 + message2);

    return 0;
}