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
	void reset()
	{
		k = nullptr;
		K = nullptr;
		pieces.clear();
		board = Board();
	}
	Game()
	{
		board = Board();
		//p1 = Player(board, 'W');
		//p2 = Player(board, 'B');
		//initializePieces();
	}
	bool isInCheck()
	{
		for (auto pair : pieces)
		{
			if ((board.isValidMove(*board.squares[pair.second.row][pair.second.column], *board.squares[pieces[k].row][pieces[k].column])) || (board.isValidMove(*board.squares[pair.second.row][pair.second.column], *board.squares[pieces[K].row][pieces[K].column])))
			{
				return true;
			}
		}
		return false;
	}
	bool isOver()
	{
		if (k->isDead)
		{
			winner = "Black";
			return true;
		}
		else if (K->isDead)
		{
			winner = "White";
			return true;
		}
		return false;
	}
	bool isImpossibleMove(Position* currentPosition, Position* newPosition)
	{
		if (board.squares[currentPosition->row][currentPosition->column]->currentPiece->color_ != turn)
		{
			return true;
		}
		else
		{
			if (not board.isValidMove(*board.squares[currentPosition->row][currentPosition->column], *board.squares[newPosition->row][newPosition->column]))
			{
				return true;
			}
		}
		return false;
	}
	void makeMove(Position* currentPosition, Position* newPosition)
	{
		board.setPosition(*board.squares[currentPosition->row][currentPosition->column], *board.squares[newPosition->row][newPosition->column]);
		//::cout << "attempting move from position (" << currentPosition->row << "," << currentPosition->column << ") to (" << newPosition->row << "," << newPosition->column << ")" << std::endl;
		/*std::cout << "verifying correct move" << std::endl;
		std::cout << "my color is: " << turn << std::endl;
		std::cout << "the piece's color is: " << board.squares[currentPosition->row][currentPosition->column]->currentPiece->color_ << std::endl;*/
		//if (board.squares[currentPosition->row][currentPosition->column]->currentPiece->color_ == turn)
		//{
		//	//std::cout << "right color" << std::endl;
		//	
		//}
		//else
		//{
		//	//std::cout << "wrong color" << std::endl;
		//}
	}
	void initializePieces()
	{
		k = std::make_shared<King>('W');
		pieces.insert(std::pair<std::shared_ptr<Piece>, Position>(k, Position{ 0,3 }));
		board.placePiece(k, pieces[k]);

		K = std::make_shared<King>('B');
		pieces.insert(std::pair<std::shared_ptr<Piece>, Position>(K, Position{ 7,3 }));
		board.placePiece(K, pieces[K]);
	}
	void setOption1()
	{
		k = std::make_shared<King>('W');
		pieces.insert(std::pair<std::shared_ptr<Piece>, Position>(k, Position{ 3,2 }));
		board.placePiece(k, pieces[k]);

		K = std::make_shared<King>('B');
		pieces.insert(std::pair<std::shared_ptr<Piece>, Position>(K, Position{ 3,0 }));
		board.placePiece(K, pieces[K]);

		auto N = std::make_shared<Knight>('B');
		pieces.insert(std::pair<std::shared_ptr<Piece>, Position>(N, Position{ 1,0 }));
		board.placePiece(N, pieces[N]);
		std::cout << "created knight" << std::endl;

		auto r = std::make_shared<Rook>('W');
		pieces.insert(std::pair<std::shared_ptr<Piece>, Position>(r, Position{0,1}));
		board.placePiece(r, pieces[r]);
		std::cout << "created rook" << std::endl;
	}
	void setOption2()
	{
		k = std::make_shared<King>('W');
		pieces.insert(std::pair<std::shared_ptr<Piece>, Position>(k, Position{ 2,4 }));
		board.placePiece(k, pieces[k]);

		K = std::make_shared<King>('B');
		pieces.insert(std::pair<std::shared_ptr<Piece>, Position>(K, Position{ 5,7 }));
		board.placePiece(K, pieces[K]);

		auto N = std::make_shared<Knight>('B');
		pieces.insert(std::pair<std::shared_ptr<Piece>, Position>(N, Position{ 2,1 }));
		board.placePiece(N, pieces[N]);
		std::cout << "created knight" << std::endl;

		auto r = std::make_shared<Rook>('W');
		pieces.insert(std::pair<std::shared_ptr<Piece>, Position>(r, Position{ 1,5 }));
		board.placePiece(r, pieces[r]);
		std::cout << "created rook" << std::endl;
	}
	void setOption3()
	{
		k = std::make_shared<King>('W');
		pieces.insert(std::pair<std::shared_ptr<Piece>, Position>(k, Position{ 4,7 }));
		board.placePiece(k, pieces[k]);

		K = std::make_shared<King>('B');
		pieces.insert(std::pair<std::shared_ptr<Piece>, Position>(K, Position{ 5,5 }));
		board.placePiece(K, pieces[K]);

		auto N = std::make_shared<Knight>('B');
		pieces.insert(std::pair<std::shared_ptr<Piece>, Position>(N, Position{ 6,4 }));
		board.placePiece(N, pieces[N]);
		std::cout << "created knight" << std::endl;

		auto r = std::make_shared<Rook>('W');
		pieces.insert(std::pair<std::shared_ptr<Piece>, Position>(r, Position{ 0,4 }));
		board.placePiece(r, pieces[r]);
		std::cout << "created rook" << std::endl;

		auto R = std::make_shared<Rook>('B');
		pieces.insert(std::pair<std::shared_ptr<Piece>, Position>(R, Position{ 7,6 }));
		board.placePiece(R, pieces[R]);
		std::cout << "created rook" << std::endl;
	}
	void setOption4()
	{
		k = std::make_shared<King>('W');
		pieces.insert(std::pair<std::shared_ptr<Piece>, Position>(k, Position{ 4,3 }));
		board.placePiece(k, pieces[k]);

		K = std::make_shared<King>('B');
		pieces.insert(std::pair<std::shared_ptr<Piece>, Position>(K, Position{ 2,3 }));
		board.placePiece(K, pieces[K]);

		auto N = std::make_shared<Knight>('B');
		pieces.insert(std::pair<std::shared_ptr<Piece>, Position>(N, Position{ 1,3 }));
		board.placePiece(N, pieces[N]);
		std::cout << "created knight" << std::endl;

		auto r = std::make_shared<Rook>('W');
		pieces.insert(std::pair<std::shared_ptr<Piece>, Position>(r, Position{ 6,1 }));
		board.placePiece(r, pieces[r]);
		std::cout << "created rook" << std::endl;

		auto R = std::make_shared<Rook>('B');
		pieces.insert(std::pair<std::shared_ptr<Piece>, Position>(R, Position{ 1,0 }));
		board.placePiece(R, pieces[R]);
		std::cout << "created rook" << std::endl;
	}
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