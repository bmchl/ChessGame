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

class Square //:public QObject
{
	//Q_OBJECT
public:
	Square() :row_(0), column_(0) {};
	Square(int x, int y) : row_(x), column_(y) {};
	Square(std::shared_ptr<Position> position) : position_(position), row_(position->row), column_(position->column) {};
	int row_ = 0;
	int column_ = 0;
	std::shared_ptr<Position> position_ = nullptr;
	int maxCoordinates_ = 7;
	std::shared_ptr<Piece> currentPiece = nullptr;
private:
	
};
