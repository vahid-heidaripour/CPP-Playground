#include <iostream>
#include <cstddef>

// This code is not type safe. Use enum class instead.
/*enum PieceType {
	King = 1,
	Queen,
	Rook,
	Pawn
};*/

enum class PieceType {
	King = 1,
	Queen,
	Rook,
	Pawn
};

int main() {
	PieceType pieceType;
	pieceType = PieceType::King;
	// invalid operand
	//if (pieceType == 4)
	if (static_cast<int>(pieceType) == 4)
		std::cout << "This is a pawn" << std::endl;
	else
		std::cout << "This is not a pawn" << std::endl;

	return 0;
}