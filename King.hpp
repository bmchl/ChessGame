// Projet Final INF 1015
// Michael Banna (2147128) & Nour Zahreddine (2167661)
// fichier King.h

#pragma once
#include <string>
#include <iostream>
#include <memory>
#include <functional>
#include <cassert>
#include <iterator>
#include <vector>
#include <list>
#include "Position.hpp"
#include "Piece.hpp"


class KingInstanceException : public std::logic_error
{
public:
	using logic_error::logic_error;
	
};
class King : public Piece
{
public:
	King(char color);
	~King();
	static int getCount() { return instanceCount_; }
	void updatePossiblePositions(Position& currentPosition) override
	{
		addPossiblePosition(currentPosition.row + 1, currentPosition.column);
		addPossiblePosition(currentPosition.row - 1, currentPosition.column);
		addPossiblePosition(currentPosition.row, currentPosition.column + 1);
		addPossiblePosition(currentPosition.row, currentPosition.column - 1);
		addPossiblePosition(currentPosition.row + 1, currentPosition.column + 1);
		addPossiblePosition(currentPosition.row - 1, currentPosition.column - 1);
		addPossiblePosition(currentPosition.row + 1, currentPosition.column - 1);
		addPossiblePosition(currentPosition.row - 1, currentPosition.column + 1);
	};
	void talk(std::ostream& os) const override;
	void setIconPath() override;
	
private:
	inline static int instanceCount_ = 0;
};