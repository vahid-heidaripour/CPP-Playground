#include "ToyGrid.h"
#include <stdexcept>
#include <utility>

template <typename T>
ToyGrid<T>::ToyGrid(size_t width, size_t height)
    : mWidth(width)
    , mHeight(height)
{
    mCells.resize(mWidth);
    for (auto& column : mCells) {
        column.resize(mHeight);
    }
}

template <typename T>
void ToyGrid<T>::verifyCoordinate(size_t x, size_t y) const
{
    if (x >= mWidth || y >= mHeight) {
        throw std::out_of_range("");
    }
}

template <typename T>
const std::optional<T>& ToyGrid<T>::at(size_t x, size_t y) const
{
    verifyCoordinate(x, y);
    return mCells[x][y];
}

template <typename T>
std::optional<T>& ToyGrid<T>::at(size_t x, size_t y)
{
    return const_cast<std::optional<T>&>(std::as_const(*this).at(x, y));
}

// Explicit instantiations for the types you want to allow.
template class ToyGrid<int>;
template class ToyGrid<double>;
template class ToyGrid<std::vector<int>>;
