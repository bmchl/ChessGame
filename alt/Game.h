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
#include "Piece.h"
#include "King.h"
#include "Rook.h"
#include "Knight.h"
#include "Player.h"

#ifndef GAME_H
#define GAME_H

class Game
{
public:
	Game();
	void initializePieces();
	void play();
private:
	Board board_ = Board();
	Player p1_ = Player(board_, 'W');
	Player p2_ = Player(board_, 'B');
}
#endif