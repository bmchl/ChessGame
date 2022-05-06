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


class Knight : public Piece
{
public:
	Knight(char color) : Piece(color) { setIconPath(); };
	
	void updatePossiblePositions(Position& currentPosition) override
	{
		addPossiblePosition(currentPosition.row + 1, currentPosition.column + 2);
		addPossiblePosition(currentPosition.row + 2, currentPosition.column + 1);
		addPossiblePosition(currentPosition.row - 1, currentPosition.column - 2);
		addPossiblePosition(currentPosition.row - 2, currentPosition.column - 1);
		
		addPossiblePosition(currentPosition.row + 1, currentPosition.column - 2);
		addPossiblePosition(currentPosition.row + 2, currentPosition.column - 1);
		addPossiblePosition(currentPosition.row - 1, currentPosition.column + 2);
		addPossiblePosition(currentPosition.row - 2, currentPosition.column + 1);
	};
	
	void talk(std::ostream& os) const override;
	void setIconPath() override;
private:
};
