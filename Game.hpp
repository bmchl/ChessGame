#pragma once
#include <string>
#include <iostream>
#include <memory>
#include <functional>
#include <cassert>
#include <iterator>
#include <vector>
#include <list>
#include "Board.hpp"
#include "King.hpp"
#include "Rook.hpp"
#include "Knight.hpp"

class Game
{
private:
	Board board;

	//Player p1;
	//Player p2;

/*signals:
	void changePosition(Position& start, Position& end) {};
	void removePiece() {};
	void highlightPossiblePositions(std::list<Position*>) {};

public slots:
	void refreshPossiblePositions(Position& position)
	{

	}
	void addPiece(char type, Position& position)
	{
		switch (type)
		{
		case 'K':
			board.placePiece(std::make_shared<King>(k), position);
		}
	}*/
public:
	Game()
	{
		board = Board();
	}
	std::shared_ptr<Piece> getPiece(Position& position)
	{
		return board.squares[position.row][position.column]->currentPiece;
	}
	Position& getPosition(std::shared_ptr<Piece> piece)
	{
		return pieces[piece];
	}
	void reset();
	bool isInCheck();
	bool isOver();
	bool isImpossibleMove(Position* currentPosition, Position* newPosition);
	void makeMove(Position* currentPosition, Position* newPosition);
	void initializePieces();
	void setOption1();
	void setOption2();
	void setOption3();
	void setOption4();


	std::shared_ptr<King> k = nullptr;
	std::shared_ptr<King> K = nullptr;
	std::map<std::shared_ptr<Piece>, Position> pieces;
	char turn = 'B';
	QString winner = "";
};