#include "Board.hpp"

void Board::populate()
{
	for (int i = 0; i < 8; i++)
		{
			for (int k = 0; k < 8; k++)
				{
					squares[i][k] = std::make_unique<Square>(std::make_shared<Position>(i, k));
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
				//std::cout << *newPosition.currentPiece << " is dead" << std::endl;
				newPosition.currentPiece = nullptr;
			}
		newPosition.currentPiece = move(currentPosition.currentPiece);
		//std::cout << "positions changed" << std::endl;
		newPosition.currentPiece->possiblePositions.clear();
	}
	else
	{
		std::cout << "invalid move" << std::endl;
	}
};

void Board::placePiece(std::shared_ptr<Piece> piece, Position position)
{
	squares[position.row][position.column]->currentPiece = piece;
}

bool Board::isValidMove(Square& currentPosition, Square& newPosition)
{
	currentPosition.currentPiece->updatePossiblePositions(*currentPosition.position_);
	currentPosition.currentPiece->possiblePositions.remove_if([this, &currentPosition](auto& pos)
		{ return checkPositionOverlap(currentPosition, *squares[pos->row][pos->column]); });
	//std::cout << "possible positions:" << std::endl;
	//for (auto&& position : currentPosition.currentPiece->possiblePositions)
	//	{
	//		//std::cout << *squares[position->row][position->column];
	//	}
	//TODO: verifier si parcours entre currentPosition et newPosition est libre
	return currentPosition.currentPiece->validateMove(*newPosition.position_);
}