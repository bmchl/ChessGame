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

class Piece //: public QObject
{
	//Q_OBJECT
public:
	Piece() = default;
	virtual ~Piece() = default;
		
	Piece(Square& square, char color) :color_(color){};
	virtual void assignToSquare(Square& square) {};
	virtual void updatePossiblePositions(Square& position) {};
	bool validateMove(Square& position);
	virtual void talk(std::ostream& os) const { os << "plain piece"; };
	char color_ = 'W';
	void addPossiblePosition(int newX, int newY);
	list<Square*> possiblePositions;
	bool isDead = false;
private:
};


