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

#ifndef BOARD_H
#define BOARD_H
class Board //: public QObject
{
	//Q_OBJECT
public:
	int size = 8;
	int max = 0;
	Board();
	std::unique_ptr<Square> squares[8][8];
	std::list<std::unique_ptr<Piece>> pieces;
	void populate();
	bool checkPositionOverlap(Square& currentPosition, Square& newPosition);
	void setPosition(Square& currentPosition, Square& newPosition);
	/*void capturePiece(Square& position)
	{
	position.currentPiece->isDead = true;
	position.currentPiece = nullptr;
	}*/
	bool isValidMove(Square& currentPosition, Square& newPosition);
	private:
	
};

#endif