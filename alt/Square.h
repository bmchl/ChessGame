#pragma once
#include <string>
#include <iostream>
#include <memory>
#include <functional>
#include <cassert>
#include <iterator>
#include <vector>
#include <list>
#include "Piece.h"

#ifndef SQUARE_H
#define SQUARE_H
class Square //:public QObject
{
	//Q_OBJECT
public:
	Square() :row_(0), column_(0) {};
	Square(int x, int y) : row_(x), column_(y) {};
	int row_ = 0;
	int column_ = 0;
	int maxCoordinates_ = 7;
	shared_ptr<Piece> currentPiece = nullptr;
private:
	
};

#endif