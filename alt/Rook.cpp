#include "Rook.h"

using namespace std;

Rook::Rook(Square& square, char color) : Piece(square, color)
{
	assignToSquare(square);
};

void Rook::assignToSquare(Square& square)
{
	square.currentPiece = make_shared<Rook>(*this);
}
void Rook::updatePossiblePositions(Square& currentPosition) 
{
	for (int i = 1; i < 7; i++)
	{
		addPossiblePosition(currentPosition.row_, currentPosition.column_ + i);
		addPossiblePosition(currentPosition.row_, currentPosition.column_ - i);
		addPossiblePosition(currentPosition.row_ + i, currentPosition.column_);
		addPossiblePosition(currentPosition.row_ - i, currentPosition.column_);
	}
};
void Rook::talk(ostream& os) const 
{
	os << "rook  (" << color_ << ")";
}
	
