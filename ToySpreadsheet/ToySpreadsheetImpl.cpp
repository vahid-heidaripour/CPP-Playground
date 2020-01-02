#include "ToySpreadsheetImpl.h"
#include "ToySpreadsheet.h"
#include <stdexcept>
#include <utility>
#include <algorithm>

size_t ToySpreadsheet::Impl::sCounter;

ToySpreadsheet::Impl::Impl(const ToySpreadsheetApplication& theApp, size_t width, size_t height)
        : mId(sCounter++)
        , mWidth(std::min(width, ToySpreadsheet::kMaxWidth))
        , mHeight(std::min(height, ToySpreadsheet::kMaxHeight))
        , mTheApp(theApp)
{
    mCells = new ToySpreadsheetCell*[mWidth];
    for (size_t i = 0; i < mWidth; i++) {
        mCells[i] = new ToySpreadsheetCell[mHeight];
    }
}

ToySpreadsheet::Impl::~Impl()
{
    for (size_t i = 0; i < mWidth; i++) {
        delete[] mCells[i];
    }
    delete[] mCells;
    mCells = nullptr;
}

ToySpreadsheet::Impl::Impl(const Impl& src)
        : Impl(src.mTheApp, src.mWidth, src.mHeight)
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

void ToySpreadsheet::Impl::verifyCoordinate(size_t x, size_t y) const
{
    if (x >= mWidth || y >= mHeight) {
        throw std::out_of_range("");
    }
}

void ToySpreadsheet::Impl::setCellAt(size_t x, size_t y, const ToySpreadsheetCell& cell)
{
    verifyCoordinate(x, y);
    mCells[x][y] = cell;
}

ToySpreadsheetCell& ToySpreadsheet::Impl::getCellAt(size_t x, size_t y)
{
    verifyCoordinate(x, y);
    return mCells[x][y];
}

void ToySpreadsheet::Impl::swap(Impl& other) noexcept
{
    using std::swap;

    swap(mWidth, other.mWidth);
    swap(mHeight, other.mHeight);
    swap(mCells, other.mCells);
}

ToySpreadsheet::Impl& ToySpreadsheet::Impl::operator=(const Impl& rhs)
{
    // check for self-assignment
    if (this == &rhs) {
        return *this;
    }

    // Copy-and-swap idiom
    Impl temp(rhs); // Do all the work in a temporary instance
    swap(temp); // Commit the work with only non-throwing operations
    return *this;
}

size_t ToySpreadsheet::Impl::getId() const
{
    return mId;
}