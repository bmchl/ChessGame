#include <string>
#include <iostream>
#include <memory>
#include <functional>
#include <cassert>
#include <iterator>
#include <vector>
#include <list>
#include "Piece.hpp"
#include "Square.hpp"


class TemporaryPiece
{
public:
	TemporaryPiece(Piece& piece, Square& position) : piece_(piece), position_(position)
	{
	};
	~TemporaryPiece();
	Piece get() { return piece_; };
	operator Piece();
	
private:
	Piece& piece_;
	Square& position_;
};