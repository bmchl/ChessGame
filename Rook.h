#pragma once
#include <string>
#include <iostream>
#include <memory>
#include <functional>
#include <cassert>
#include <iterator>
#include <vector>
#include <list>
#include "Position.h"
#include "Piece.h"


class Rook : public Piece
{
public:
	Rook(char color) :Piece(color) { setIconPath(); };

	void updatePossiblePositions(Position& currentPosition) override
	{
		for (int i = 1; i < 8; i++)
		{
			addPossiblePosition(currentPosition.row, currentPosition.column + i);
			addPossiblePosition(currentPosition.row, currentPosition.column - i);
			addPossiblePosition(currentPosition.row + i, currentPosition.column);
			addPossiblePosition(currentPosition.row - i, currentPosition.column);
		}
	};
	void talk(std::ostream& os) const override
	{
		os << "rook  (" << color_ << ")";
	}
	void setIconPath() override
	{
		if (color_ == 'W')
		{
			iconPath = "./img/wrook.png";
		}
		else if (color_ == 'B')
		{
			iconPath = "./img/brook.png";
		}
	}
private:
};
