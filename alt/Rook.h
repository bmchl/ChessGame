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
#include "Piece.h"

#ifndef ROOK_H
#define ROOK_H

class Rook : public Piece
{
public:
	Rook(unique_ptr<Square>& square, char color);
	void assignToSquare(unique_ptr<Square>& square);
	void updatePossiblePositions(Square& currentPosition) override;
	void talk(std::ostream& os) const override;
private:
};
#endif