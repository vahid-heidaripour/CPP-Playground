#ifndef _TOYGAMEBOARD_H_
#define _TOYGAMEBOARD_H_

#include <cstddef>

class ToyGamePiece {};

class ToyGameBoard
{
public:
    // general-purpose GameBoard allows user to specify its dimensions
    explicit ToyGameBoard(size_t width = kDefaultWidth, size_t height = kDefaultHeight);
    ToyGameBoard(const ToyGameBoard& src); // Copy constructor
    virtual ~ToyGameBoard() noexcept;
    ToyGameBoard& operator=(const ToyGameBoard& rhs); // Assignment operator

    ToyGamePiece& at(size_t x, size_t y);
    const ToyGamePiece& at(size_t x, size_t y) const;

    size_t getHeight() const noexcept { return mHeight; }
    size_t getWidth() const noexcept { return mWidth; }

    static const size_t kDefaultWidth = 100;
    static const size_t kDefaultHeight = 100;

    friend void swap(ToyGameBoard& first, ToyGameBoard& second) noexcept;

private:
    void cleanup() noexcept;
    void verifyCoordinate(size_t x, size_t y) const;

    // Objects dynamically allocate space for the game pieces.
    ToyGamePiece** mCells = nullptr;
    size_t mWidth = 0, mHeight = 0;
};

#endif //_TOYGAMEBOARD_H_
