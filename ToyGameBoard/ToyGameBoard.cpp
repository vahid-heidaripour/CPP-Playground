#include "ToyGameBoard.h"
#include <stdexcept>
#include <utility>

using namespace std;

ToyGameBoard::ToyGameBoard(size_t width, size_t height)
    : mWidth(width)
    , mHeight(height)
{
    mCells.resize(mWidth);
    for (auto& column : mCells) {
        column.resize(mHeight);
    }
}

ToyGameBoard::ToyGameBoard(const ToyGameBoard& src)
    : ToyGameBoard(src.mWidth, src.mHeight)
{
    // The ctor-initializer of this constructor delegates first to the
    // non-copy constructor to allocate the proper amount of memory.

    // The next step is to copy the data.
    for (size_t i = 0; i < mWidth; i++) {
        for (size_t j = 0; j < mHeight; j++) {
            if (src.mCells[i][j])
                mCells[i][j] = src.mCells[i][j]->clone();
        }
    }
}

void ToyGameBoard::verifyCoordinate(size_t x, size_t y) const
{
    if (x >= mWidth || y >= mHeight) {
        throw std::out_of_range("");
    }
}

void swap(ToyGameBoard &first, ToyGameBoard &second) noexcept
{
    using std::swap;

    swap(first.mWidth, second.mWidth);
    swap(first.mHeight, second.mHeight);
    swap(first.mCells, second.mCells);
}

ToyGameBoard& ToyGameBoard::operator=(const ToyGameBoard& rhs)
{
    // check for self assignment
    if (this == &rhs) {
        return *this;
    }

    ToyGameBoard temp(rhs); // Do all the work in a temporary instance
    swap(*this, temp); // Commit the work with only non-throwing operations
    return *this;
}

const unique_ptr<ToyGamePiece>& ToyGameBoard::at(size_t x, size_t y) const
{
    verifyCoordinate(x, y);
    return mCells[x][y];
}

unique_ptr<ToyGamePiece>& ToyGameBoard::at(size_t x, size_t y)
{
    return const_cast<unique_ptr<ToyGamePiece>&>(as_const(*this).at(x, y));
}