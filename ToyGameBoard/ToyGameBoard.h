#ifndef _TOYGAMEBOARD_H_
#define _TOYGAMEBOARD_H_

#include <cstddef>
#include <vector>
#include <memory>

class ToyGamePiece
{
public:
    virtual std::unique_ptr<ToyGamePiece> clone() const = 0;
};

class ToyGameBoard
{
public:
    explicit ToyGameBoard(size_t width = kDefaultWidth, size_t height = kDefaultHeight);
    ToyGameBoard(const ToyGameBoard& src); //copy constructor
    virtual ~ToyGameBoard() = default; //virtual default destructor
    ToyGameBoard& operator=(const ToyGameBoard& rhs); //assignment operator

    // explicitly default a move constructor and move assignment operator
    ToyGameBoard(ToyGameBoard&& src) = default;
    ToyGameBoard& operator=(ToyGameBoard&& src) = default;

    std::unique_ptr<ToyGamePiece>& at(size_t x, size_t y);
    const std::unique_ptr<ToyGamePiece>& at(size_t x, size_t y) const;

    size_t getHeight() const { return mHeight; }
    size_t getWidth() const { return mWidth; }

    static const size_t kDefaultWidth = 10;
    static const size_t kDefaultHeight = 10;

    friend void swap(ToyGameBoard& first, ToyGameBoard& second) noexcept;
private:
    void verifyCoordinate(size_t x, size_t y) const;

    std::vector<std::vector<std::unique_ptr<ToyGamePiece>>> mCells;
    size_t mWidth, mHeight;
};

#endif //_TOYGAMEBOARD_H_
