#include "Piece.h"
using namespace std;


bool Piece::validateMove(Square*& position)
{
	bool valid = false;
	for (auto& possiblePosition : possiblePositions)
	{
		if ((position->row_ == possiblePosition->row_) && (position->column_ == possiblePosition->column_))
		{
		valid = true;
		cout << "move is among the piece's possible positions" << endl;
		}
	}
	return valid;
};



void Piece::addPossiblePosition(int newX, int newY)
{
	if ((newX <= 7) &&
		(newY <= 7) &&
		(newX >= 0) &&
		(newY >= 0))
		{
			possiblePositions.push_back(new Square(newX, newY));
		}
}


ostream& operator<< (ostream& os, const Piece& piece)
{
	piece.talk(os);
	return os;
}

ostream& operator<< (ostream& os, const Square& square)
{
	os << "square at position (" << square.row_ << "," << square.column_ << ")";
	
	if (square.currentPiece != nullptr)
		{
			os << " with " << *square.currentPiece;
		}
	os << "\n";
	return os;
}