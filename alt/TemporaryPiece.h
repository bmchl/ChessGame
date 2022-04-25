#include <iostream>
#pragma once
#include <string>
#include <iostream>
#include <memory>
#include <functional>
#include <cassert>
#include <iterator>
#include <vector>
#include <list>
#include "Square.h"
#include "Board.h"

#ifndef TEMPORARYPIECE_H
#define TEMPORARYPIECE_H
class TemporaryPiece
{
public:
	TemporaryPiece(Piece& piece, unique_ptr<Square>& position) : piece_(piece), position_(position)
	{
		piece_.assignToSquare(position_);
	};
	~TemporaryPiece()
	{
		piece_.isDead = true;
		position_->currentPiece = nullptr;
	};
	Piece get() { return piece_; };
	operator Piece() { return get(); };
private:
	Piece& piece_;
	unique_ptr<Square>& position_;
};
#endif