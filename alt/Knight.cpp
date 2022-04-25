#include "Knight.h"

using namespace std;

Knight::Knight(Square& square, char color)
{
	assignToSquare(square);
};

void Knight::assignToSquare(Square& square)
{
	square.currentPiece = make_shared<Knight>(*this);
}
	
void Knight::updatePossiblePositions(Square& currentPosition) override
{
	addPossiblePosition(currentPosition.row_ + 1, currentPosition.column_ + 2);
	addPossiblePosition(currentPosition.row_ + 2, currentPosition.column_ + 1);
	addPossiblePosition(currentPosition.row_ - 1, currentPosition.column_ - 2);
	addPossiblePosition(currentPosition.row_ - 2, currentPosition.column_ - 1);
	
	addPossiblePosition(currentPosition.row_ + 1, currentPosition.column_ - 2);
	addPossiblePosition(currentPosition.row_ + 2, currentPosition.column_ - 1);
	addPossiblePosition(currentPosition.row_ - 1, currentPosition.column_ + 2);
	addPossiblePosition(currentPosition.row_ - 2, currentPosition.column_ + 1);
};
void Knight::talk(ostream& os) const override
{
	os << "knight (" << color_ << ")";
}
	
