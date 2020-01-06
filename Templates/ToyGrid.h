#ifndef _TOYGRID_H_
#define _TOYGRID_H_

#include <cstddef>
#include <vector>
#include <optional>

template <typename T>
class ToyGrid
{
public:
    explicit ToyGrid(size_t width = kDefaultWidth, size_t height = kDefaultHeight);
    virtual ~ToyGrid() = default;

    // Explicitly default a copy constructor and copy assignment operator.
    ToyGrid(const ToyGrid& src) = default;
    ToyGrid<T>& operator=(const ToyGrid& rhs) = default;

    // Explicitly default a move constructor and move assignment operator.
    ToyGrid(ToyGrid&& src) = default;
    ToyGrid<T>& operator=(ToyGrid&& rhs) = default;

    std::optional<T>& at(size_t x, size_t y);
    const std::optional<T>& at(size_t x, size_t y) const;

    size_t getHeight() const { return mHeight; }
    size_t getWidth() const { return mWidth; }

    static const size_t kDefaultWidth = 10;
    static const size_t kDefaultHeight = 10;

private:
    void verifyCoordinate(size_t x, size_t y) const;

    std::vector<std::vector<std::optional<T>>> mCells;
    size_t mWidth, mHeight;
};

#endif //_TOYGRID_H_
