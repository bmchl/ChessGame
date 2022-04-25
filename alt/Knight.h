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

#ifndef KNIGHT_H
#define KNIGHT_H

class Knight : public Piece
{
public:
	Knight(Square& square, char color);
	void assignToSquare(Square& square);
	void updatePossiblePositions(Square& currentPosition) override;
	void talk(std::ostream& os) const override;

private:
};
#endif