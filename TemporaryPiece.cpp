#include "TemporaryPiece.hpp"

TemporaryPiece::~TemporaryPiece()
{
	piece_.isDead = true;
	position_.currentPiece = nullptr;
	//piece_.~Piece();
};
TemporaryPiece::operator Piece() { return get(); };