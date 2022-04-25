#include "Player.h"

using namespace std;

void Player::makeMove(Square& currentPosition, Square& newPosition)
{
	if (currentPosition.currentPiece->color_ == color_)
	{
		board_->setPosition(currentPosition, newPosition);
	}
	else
	{
		cout << "wrong color" << endl;
	}
}