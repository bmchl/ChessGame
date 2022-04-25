#include "Board.h"

using namespace std;


Board::Board()
{
	size = 8;
	max = size - 1;
	populate();
};
void Board::populate()
{
	for (int i = 0; i < 8; i++)
	{
		for (int k = 0; k < 8; k++)
		{
			squares[i][k] = make_unique<Square>(i, k);
		}
	}
}
bool Board::checkPositionOverlap(Square& currentPosition, Square& newPosition)
{
	if (newPosition.currentPiece != nullptr)
		{
			if (newPosition.currentPiece->color_ == currentPosition.currentPiece->color_)
				{
					if ((newPosition.row_ != currentPosition.row_) || (newPosition.column_ != currentPosition.column_))
						{
							return true;
						}
				}
		}
	return false;
}
void Board::setPosition(Square& currentPosition, Square& newPosition)
{
	if (isValidMove(currentPosition, newPosition))
	{
		if (newPosition.currentPiece != nullptr)
		{
			newPosition.currentPiece->isDead = true;
			cout << *newPosition->currentPiece << " is dead" << endl;
			newPosition.currentPiece = nullptr;
		}
			currentPosition.currentPiece->assignToSquare(newPosition);
			currentPosition.currentPiece = nullptr;
			cout << "positions changed" << endl;
	}
	else
	{
		cout << "invalid move" << endl;
	}
};
/*void capturePiece(Square& position)
{
position.currentPiece->isDead = true;
position.currentPiece = nullptr;
}*/
bool Board::isValidMove(Square& currentPosition, Square& newPosition)
{
	currentPosition.currentPiece->updatePossiblePositions(currentPosition);
	currentPosition.currentPiece->possiblePositions.remove_if([this, &currentPosition](auto& pos)
		{ return checkPositionOverlap(currentPosition,*pos); });
	cout << "possible positions:" << endl;
	for (auto&& position : currentPosition.currentPiece->possiblePositions)
	{
		cout << *position;
	}
	//TODO: verifier si parcours entre currentPosition et newPosition est libre
	return currentPosition.currentPiece->validateMove(newPosition);
}
