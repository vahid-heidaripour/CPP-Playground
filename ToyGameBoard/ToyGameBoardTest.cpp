#include "ToyGameBoard.h"

class ToyChessPiece : public ToyGamePiece
{
public:
    virtual std::unique_ptr<ToyGamePiece> clone() const override;
};

std::unique_ptr<ToyGamePiece> ToyChessPiece::clone() const
{
    // Call the copy constructor to copy this instance
    return std::make_unique<ToyChessPiece>(*this);
}

void processToyGameBoard(const ToyGameBoard& board)
{
    const std::unique_ptr<ToyGamePiece>& pawn = board.at(0, 0);

    // Doesn't compile
    //board.at(1, 2) = std::make_unique<ChessPiece>();
}

int main()
{
    ToyGameBoard toyChessBoard(8, 8);
    auto pawn = std::make_unique<ToyChessPiece>();
    toyChessBoard.at(0, 0) = std::move(pawn);
    toyChessBoard.at(0, 1) = std::make_unique<ToyChessPiece>();
    toyChessBoard.at(0, 1) = nullptr;

    ToyGameBoard toyBoard;
    toyBoard = toyChessBoard;

    processToyGameBoard(toyBoard);

    return 0;
}