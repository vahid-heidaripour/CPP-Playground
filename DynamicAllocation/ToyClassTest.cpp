#include <iostream>
#include "ToyClass.h"

int main()
{
    size_t width = 2, height = 3;
    ToyClass toy(width, height);
    for (size_t i = 0; i < width; i++) {
        for (size_t j = 0; j < height; j++) {
            toy.setCellAt(i, j, i * j);
        }
    }

    for (size_t i = 0; i < width; i++) {
        for (size_t j = 0; j < height; j++) {
            std::cout << "The value in cell " << i << ", " << j << " is: " << toy.getCellAt(i, j) << std::endl;
        }
    }
    return 0;
}