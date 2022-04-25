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

class TemporaryPiece: public Piece
{
public:
	TemporaryPiece(Piece& piece, Square& position);
	~TemporaryPiece();
	
private:
	Piece& piece_;
	Square& position_;
};