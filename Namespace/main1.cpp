#include <iostream>
#include "header.h"

using namespace mycode;

void foo() {
    std::cout << "This foo is in source file!" << std::endl;
}

int main() {
    foo(); // now this call function is ambiguous
    mycode::foo();
    return 0;
}
