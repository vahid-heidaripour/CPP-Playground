#include "ToyGameBoard.h"

void processGameBoard(const ToyGameBoard& board)
{
    const ToyGamePiece& piece = board.at(0, 0);

    // Doesn't compile
    //board.at(1, 2) = piece;
}

int main()
{
    ToyGameBoard board(10, 10);
    ToyGamePiece piece;

    board.at(0, 0) = piece;
    board.at(0, 1) = board.at(0, 0);

    ToyGameBoard board2;
    board2 = board;

    processGameBoard(board2);

    return 0;
}
