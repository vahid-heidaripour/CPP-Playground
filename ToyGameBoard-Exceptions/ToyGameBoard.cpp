#include "ToyGameBoard.h"
#include <stdexcept>
#include <utility>
#include <new>

using namespace std;

ToyGameBoard::ToyGameBoard(size_t width, size_t height)
{
    mCells = new ToyGamePiece*[width] {};	// Array is zero-initialized!

    // Don't initialize the mWidth and mHeight members in the ctor-
    // initializer. These should only be initialized when the above
    // mCells allocation succeeds!
    mWidth = width;
    mHeight = height;

    try {
        for (size_t i = 0; i < mWidth; i++) {
            mCells[i] = new ToyGamePiece[mHeight];
        }
    } catch (...) {
        cleanup();
        // Nest any caught exception inside a bad_alloc exception.
        std::throw_with_nested(std::bad_alloc());
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
            mCells[i][j] = src.mCells[i][j];
        }
    }
}

ToyGameBoard::~ToyGameBoard() noexcept
{
    cleanup();
}

void ToyGameBoard::cleanup() noexcept
{
    for (size_t i = 0; i < mWidth; i++)
        delete[] mCells[i];
    delete[] mCells;
    mCells = nullptr;
    mWidth = mHeight = 0;
}

void ToyGameBoard::verifyCoordinate(size_t x, size_t y) const
{
    if (x >= mWidth)
        throw out_of_range("x-coordinate beyond width");
    if (y >= mHeight)
        throw out_of_range("y-coordinate beyond height");
}

void swap(ToyGameBoard& first, ToyGameBoard& second) noexcept
{
    using std::swap;

    swap(first.mWidth, second.mWidth);
    swap(first.mHeight, second.mHeight);
    swap(first.mCells, second.mCells);
}

ToyGameBoard& ToyGameBoard::operator=(const ToyGameBoard& rhs)
{
    // check for self-assignment
    if (this == &rhs) {
        return *this;
    }

    // Copy-and-swap idiom
    ToyGameBoard temp(rhs); // Do all the work in a temporary instance
    swap(*this, temp);   // Commit the work with only non-throwing operations
    return *this;
}

const ToyGamePiece& ToyGameBoard::at(size_t x, size_t y) const
{
    verifyCoordinate(x, y);
    return mCells[x][y];
}

ToyGamePiece& ToyGameBoard::at(size_t x, size_t y)
{
    return const_cast<ToyGamePiece&>(std::as_const(*this).at(x, y));
}
