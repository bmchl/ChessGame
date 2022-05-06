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
#include "Knight.h"
#include "Board.h"
#include "King.h"
#include "Rook.h"

class Game
{
private:
	Board board;

	//Player p1;
	//Player p2;

	std::shared_ptr<King> k = nullptr;
	std::shared_ptr<King> K = nullptr;

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
	std::map<std::shared_ptr<Piece>, Position> pieces;
	char turn = 'B';

	QString winner = "";

	std::shared_ptr<Piece> getPiece(Position& position)
	{
		return board.squares[position.row][position.column]->currentPiece;
	}
	Position& getPosition(std::shared_ptr<Piece> piece)
	{
		return pieces[piece];
	}
	void reset();
	Game()
	{
		board = Board();
		//p1 = Player(board, 'W');
		//p2 = Player(board, 'B');
		//initializePieces();
	}
	bool isInCheck();
	bool isOver();
	bool isImpossibleMove(Position* currentPosition, Position* newPosition);
	void makeMove(Position* currentPosition, Position* newPosition);
	void initializePieces();
	void setOption1();
	void setOption2();
	void setOption3();
	void setOption4();
	//void play()
	//{
	//	bool gameOver = false;
	//	std::cout << "game start" << std::endl;
	//	std::cout << "here are the current pieces on the board:" << std::endl;
	//	for (int i = 0; i < 8; i++)
	//	{
	//		for (int j = 0; j < 8; j++)
	//		{
	//			if (board.squares[i][j]->currentPiece != nullptr)
	//			{
	//				std::cout << *board.squares[i][j];
	//			}
	//		}
	//	}
	//	while (!gameOver)
	//	{
	//		if ((k->isDead) || (K->isDead))
	//		{
	//			gameOver = true;
	//			break;
	//		}
	//		if (turn == 'W') { turn = 'B'; }
	//		else if (turn == 'B') { turn = 'W'; }
	//		std::cout << "current turn: " << turn << std::endl;
	//		if (turn == 'W') 
	//		{ 
	//			//std::cout << "player 1: your turn. \nselect a piece on the board to move, one coordinate at a time \nexample, to access the piece at (3,0): \n 3 \n 0\n\n"; 
	//			//std::cin >> currentRow;
	//			//std::cin >> currentColumn;
	//			//std::cout << "player 1: pick a destination location\n";
	//			//std::cin >> newRow;
	//			//std::cin >> newColumn;
	//			while (currentRow == 8 || currentColumn == 8 || newRow == 8 || newColumn == 8)
	//			{
	//			}
	//			makeMove(*board.squares[currentRow][currentColumn], *board.squares[newRow][newColumn]);
	//			currentRow = 8;
	//			currentColumn = 8;
	//			newRow = 8;
	//			newColumn = 8;
	//		}
	//		else if (turn == 'B')
	//		{
	//			//std::cout << "player 2: your turn. \nselect a piece on the board to move, one coordinate at a time \nexample, to access the piece at (3,0): \n 3 \n 0\n\n";
	//			//std::cin >> currentRow;
	//			//std::cin >> currentColumn;
	//			//std::cout << "player 2: pick a destination location\n";
	//			//std::cin >> newRow;
	//			//std::cin >> newColumn;
	//			while (currentRow == 8 || currentColumn == 8 || newRow == 8 || newColumn == 8)
	//			{
	//			}
	//			makeMove(*board.squares[currentRow][currentColumn], *board.squares[newRow][newColumn]);
	//			currentRow = 8;
	//			currentColumn = 8;
	//			newRow = 8;
	//			newColumn = 8;
	//		}
	//	}
	//	std::cout << "game over";
	//}
};