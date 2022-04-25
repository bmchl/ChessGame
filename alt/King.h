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


class KingInstanceException : public std::logic_error
{
public:
	using logic_error::logic_error;	
};

class King : public Piece
{
public:
	King(Square& square, char color);
	~King()
	{
		instanceCount_--;
	};
	static int getCount() { return instanceCount_; }

	void assignToSquare(Square& square);

	void updatePossiblePositions(Square& currentPosition) override;
	void talk(std::ostream& os) const override;
	

private:
	inline static int instanceCount_ = 0;
};
