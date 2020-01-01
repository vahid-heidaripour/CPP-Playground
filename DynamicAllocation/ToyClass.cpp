#include <iostream>
#include "ToyClass.h"

ToyClass::ToyClass(size_t width, size_t height)
    : mWidth(width), mHeight(height)
{
    cells = new int*[mWidth];
    for (size_t i = 0; i < mWidth; i++) {
        cells[i] = new int[mHeight];
    }
}

ToyClass::~ToyClass()
{
    for (size_t i = 0; i < mWidth; i++) {
        delete [] cells[i];
    }
    delete [] cells;
    cells = nullptr;
}

void ToyClass::verifyCoordinate(size_t x, size_t y) const
{
    if (x >= mWidth || y >= mHeight) {
        throw std::out_of_range("");
    }
}

void ToyClass::setCellAt(size_t x, size_t y, const int &value)
{
    verifyCoordinate(x, y);
    cells[x][y] = value;
}

int& ToyClass::getCellAt(size_t x, size_t y)
{
    verifyCoordinate(x, y);
    return cells[x][y];
}

