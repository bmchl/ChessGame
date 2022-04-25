#include "King.h"

using namespace std;

King::King(Square& square, char color)
{
	try
	{
		if (instanceCount_ == 2)
		{
			throw KingInstanceException("max instances reached\n");
		}
		else
		{
			Piece(square, color);
			assignToSquare(square);
			instanceCount_++;
		}
	}
	catch (KingInstanceException& e)//mettre dans une autre classe qui controle la vue = interface 
	{
		cout << e.what();
	}
};

void King::assignToSquare(Square& square)
{
	square.currentPiece = make_shared<King>(*this);
}

void King::updatePossiblePositions(Square& currentPosition) override
{
	addPossiblePosition(currentPosition.row_, currentPosition.column_);
	addPossiblePosition(currentPosition.row_ + 1, currentPosition.column_);
	addPossiblePosition(currentPosition.row_ - 1, currentPosition.column_);
	addPossiblePosition(currentPosition.row_, currentPosition.column_ + 1);
	addPossiblePosition(currentPosition.row_, currentPosition.column_ - 1);
	addPossiblePosition(currentPosition.row_ + 1, currentPosition.column_ + 1);
	addPossiblePosition(currentPosition.row_ - 1, currentPosition.column_ - 1);
	addPossiblePosition(currentPosition.row_ + 1, currentPosition.column_ - 1);
	addPossiblePosition(currentPosition.row_ - 1, currentPosition.column_ + 1);
};
void King::talk(std::ostream& os) const override
{
	os << "king (" << color_ << ")";
}
