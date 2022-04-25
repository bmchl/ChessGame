#pragma once
#include <string>
#include <iostream>
#include <memory>
#include <functional>
#include <cassert>
#include <iterator>
#include <vector>
#include <list>
#include "Board.h"
#include "Square.h"

#ifndef PLAYER_H
#define PLAYER_H
class Player
{
public:
	Player(Board& board, char color) : color_(color) { board_ = make_shared<Board>(board); };
	char color_;
	shared_ptr<Board> board_;
	void makeMove(Square& currentPosition, Square& newPosition);
private:
};

#endif