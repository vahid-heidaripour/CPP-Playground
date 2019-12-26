#include <iostream>
#include "header.h"

namespace mycode {
    void foo() {
        std::cout << "This foo is in mycode namespace!" << std::endl;
    }
}

void foo() {
    std::cout << "This foo is in source file!" << std::endl;
}

int main() {
    foo();
    mycode::foo();
    return 0;
}
