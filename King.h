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
#include "Position.h"
#include "Piece.h"


class KingInstanceException : public std::logic_error
{
public:
	using logic_error::logic_error;
	
};
class King : public Piece
{
public:
	//King() = default;
	//King(char color) : Piece(color)
	//{
	
	//}
	King(char color) : Piece( color){};
	~King();
	static int getCount() { return instanceCount_; }
	
	//void assignToSquare(Square& square)
	//{
	//	square.currentPiece = std::make_shared<King>(*this);
	//}
	
	void updatePossiblePositions(Position& currentPosition) override
	{
		//addPossiblePosition(currentPosition.row, currentPosition.column);
		addPossiblePosition(currentPosition.row + 1, currentPosition.column);
		addPossiblePosition(currentPosition.row - 1, currentPosition.column);
		addPossiblePosition(currentPosition.row, currentPosition.column + 1);
		addPossiblePosition(currentPosition.row, currentPosition.column - 1);
		addPossiblePosition(currentPosition.row + 1, currentPosition.column + 1);
		addPossiblePosition(currentPosition.row - 1, currentPosition.column - 1);
		addPossiblePosition(currentPosition.row + 1, currentPosition.column - 1);
		addPossiblePosition(currentPosition.row - 1, currentPosition.column + 1);
	};
	void talk(std::ostream& os) const override
	{
		os << "king (" << color_ << ")";
	}
	void setIconPath() override
	{
		if (color_ == 'W')
			{
				iconPath = "./img/wking.png";
			}
		else if (color_ == 'B')
			{
				iconPath = "./img/bking.png";
			}
	}
	
private:
	inline static int instanceCount_ = 0;
};