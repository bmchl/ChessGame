// TD6 INF 1015
// Michael Banna (2147128) & Nour Zahreddine (2167661)
// fichier Chess.hpp
// Il contient toutes les classes du projet.
// Nous n'avons pas encore parvenu a le separer en plusieurs fichiers .h et .cpp.
// Des améliorations sont cependant étaient faites en suivant les commentaires donnés pour le livrable 1.
// Notre premier namespace "logic" se situe ici.

#pragma once
#include <string>
#include <iostream>
#include <memory>
#include <functional>
#include <cassert>
#include <iterator>
#include <vector>
#include <list>
#include "Position.hpp"

#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QObject>
#pragma pop()

namespace logic {
	class Board;
	class Square;
	class Player;
	class Piece;
	class King;
	class Knight;
	class Rook;

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

	class Piece //: public QObject
	{
		//Q_OBJECT
	public:
		Piece() = default;
		virtual ~Piece() = default;
		Piece(char color) : color_(color) {};
		/*Piece(Square& square, char color) : color_(color)
		{
		}*/
		//virtual void assignToSquare(Square& square) {};
		virtual void updatePossiblePositions(Position& position) {};
		bool validateMove(Position& position)
		{
			bool valid = false;
			for (auto& possiblePosition : possiblePositions)
			{
				if ((position.row == possiblePosition->row) &&
					(position.column == possiblePosition->column))
				{
					valid = true;
					std::cout << "move is among the piece's possible positions" << std::endl;
				}
			}
			return valid;
		};
		virtual void talk(std::ostream& os) const { os << "plain piece"; };
		char color_ = 'W';
		/*void clearPossiblePositions()
		{
			while (!possiblePositions.empty())
			{
				delete possiblePositions.front(), possiblePositions.pop_front();
			}
		}*/
		void addPossiblePosition(int newX, int newY)
		{
			if ((newX <= 7) &&
				(newY <= 7) &&
				(newX >= 0) &&
				(newY >= 0))
			{
				possiblePositions.push_back(new Position{ newX, newY });
			}
		}
		std::list<Position*> possiblePositions;
		bool isDead = false;
	private:
	};


	std::ostream& operator<< (std::ostream& os, const Piece& piece)
	{
		piece.talk(os);
		return os;
	}

	std::ostream& operator<< (std::ostream& os, const Square& square)
	{
		os << "square at position (" << square.row_ << "," << square.column_ << ")";

		if (square.currentPiece != nullptr)
		{
			os << " with " << *square.currentPiece;
		}
		os << "\n";
		return os;
	}

	class Board //: public QObject
	{
		//Q_OBJECT
	public:
		int size = 8;
		int max = 0;
		Board()
		{
			size = 8;
			max = size - 1;
			populate();
		};
		std::unique_ptr<Square> squares[8][8];
		//std::list<std::unique_ptr<Piece>> pieces;
		void populate()
		{
			for (int i = 0; i < 8; i++)
			{
				for (int k = 0; k < 8; k++)
				{
					squares[i][k] = std::make_unique<Square>(std::make_shared<Position>( i,k ));
				}
			}
		}
		bool checkPositionOverlap(Square& currentPosition, Square& newPosition)
		{
			if (newPosition.currentPiece != nullptr)
			{
				if (newPosition.currentPiece->color_ == currentPosition.currentPiece->color_)
				{
					if ((newPosition.row_ != currentPosition.row_) || (newPosition.column_ != currentPosition.column_))
					{
						return true;
					}
				}
			}
			return false;
		}
		void setPosition(Square& currentPosition, Square& newPosition)
		{
			if (isValidMove(currentPosition, newPosition))
			{
				if (newPosition.currentPiece != nullptr)
				{
					newPosition.currentPiece->isDead = true;
					std::cout << *newPosition.currentPiece << " is dead" << std::endl;
					newPosition.currentPiece = nullptr;
				}
				//currentPosition.currentPiece->assignToSquare(newPosition);
				newPosition.currentPiece = move(currentPosition.currentPiece);
				//currentPosition.currentPiece = nullptr;
				std::cout << "positions changed" << std::endl;
				newPosition.currentPiece->possiblePositions.clear();
			}
			else
			{
				std::cout << "invalid move" << std::endl;
			}
		};
		void placePiece(std::shared_ptr<Piece> piece, Position position)
		{
			squares[position.row][position.column]->currentPiece = piece;
		}
		/*void capturePiece(Square& position)
		{
			position.currentPiece->isDead = true;
			position.currentPiece = nullptr;
		}*/
		bool isValidMove(Square& currentPosition, Square& newPosition)
		{
			currentPosition.currentPiece->updatePossiblePositions(*currentPosition.position_);
			currentPosition.currentPiece->possiblePositions.remove_if([this, &currentPosition](auto& pos)
				{ return checkPositionOverlap(currentPosition, *squares[pos->row][pos->column]); });
			std::cout << "possible positions:" << std::endl;
			for (auto&& position : currentPosition.currentPiece->possiblePositions)
			{
				std::cout << *squares[position->row][position->column];
			}
			//TODO: verifier si parcours entre currentPosition et newPosition est libre
			return currentPosition.currentPiece->validateMove(*newPosition.position_);
		}
	private:

	};

	class KingInstanceException : public std::logic_error
	{
	public:
		using logic_error::logic_error;

	};
	class King : public Piece
	{
	public:
		King() = default;
		//King(char color) : Piece(color)
		//{

		//}
		King(char color) : Piece( color)
		{
			if (instanceCount_ >= 2)
			{
				throw KingInstanceException("max instances reached\n");
			}
			instanceCount_++;
			std::cout << "created new ";
			talk(std::cout);
			std::cout << std::endl;
		};
		~King()
		{
			std::cout << "destroying ";
			talk(std::cout);
			std::cout << std::endl;
			instanceCount_--;
		};
		static int getCount() { return instanceCount_; }

		//void assignToSquare(Square& square)
		//{
		//	square.currentPiece = std::make_shared<King>(*this);
		//}

		void updatePossiblePositions(Position& currentPosition) override
		{
			addPossiblePosition(currentPosition.row, currentPosition.column);
			addPossiblePosition(currentPosition.row + 1, currentPosition.column);
			addPossiblePosition(currentPosition.row - 1, currentPosition.column);
			addPossiblePosition(currentPosition.row, currentPosition.column + 1);
			addPossiblePosition(currentPosition.row, currentPosition.column - 1);
			addPossiblePosition(currentPosition.row + 1, currentPosition.column + 1);
			addPossiblePosition(currentPosition.row - 1, currentPosition.column - 1);
			addPossiblePosition(currentPosition.row + 1, currentPosition.column - 1);
			addPossiblePosition(currentPosition.row - 1, currentPosition.column + 1);
		};
		void talk(std::ostream& os) const override
		{
			os << "king (" << color_ << ")";
		}

	private:
		inline static int instanceCount_ = 0;
	};

	class Rook : public Piece
	{
	public:
		Rook(char color) :Piece(color) {};

		void updatePossiblePositions(Position& currentPosition) override
		{
			for (int i = 1; i < 7; i++)
			{
				addPossiblePosition(currentPosition.row, currentPosition.column + i);
				addPossiblePosition(currentPosition.row, currentPosition.column - i);
				addPossiblePosition(currentPosition.row + i, currentPosition.column);
				addPossiblePosition(currentPosition.row - i, currentPosition.column);
			}
		};
		void talk(std::ostream& os) const override
		{
			os << "rook  (" << color_ << ")";
		}

	private:
	};

	class Knight : public Piece
	{
	public:
		Knight(char color) : Piece(color) {};

		void updatePossiblePositions(Position& currentPosition) override
		{
			addPossiblePosition(currentPosition.row + 1, currentPosition.column + 2);
			addPossiblePosition(currentPosition.row + 2, currentPosition.column + 1);
			addPossiblePosition(currentPosition.row - 1, currentPosition.column - 2);
			addPossiblePosition(currentPosition.row - 2, currentPosition.column - 1);

			addPossiblePosition(currentPosition.row + 1, currentPosition.column - 2);
			addPossiblePosition(currentPosition.row + 2, currentPosition.column - 1);
			addPossiblePosition(currentPosition.row - 1, currentPosition.column + 2);
			addPossiblePosition(currentPosition.row - 2, currentPosition.column + 1);
		};

		void talk(std::ostream& os) const override
		{
			os << "knight (" << color_ << ")";
		}
	private:
		
	};

	//class Player
	//{
	//public:
	//	Player() = default; 
	//	// { board_ = Board(); };
	//	Player(Board& board, char color) : board_(&board), color_(color) {  };
	//	Player operator = (const Player& p) { return Player(*p.board_, p.color_); }
	//	char color_;
	//	void makeMove(Square& currentPosition, Square& newPosition)
	//	{
	//		std::cout << "verifying correct move" << std::endl;
	//		std::cout << "my color is: " << color_ << std::endl;
	//		std::cout << "the piece's color is: " << currentPosition.currentPiece->color_ << std::endl;
	//		if (currentPosition.currentPiece->color_ == color_)
	//		{
	//			std::cout << "right color" << std::endl;
	//			board_->setPosition(currentPosition, newPosition);
	//		}
	//		else
	//		{
	//			std::cout << "wrong color" << std::endl;
	//		}
	//	}
	//private:
	//	Board* board_;
	//};

	class TemporaryPiece
	{
	public:
		TemporaryPiece(Piece& piece, Square& position) : piece_(piece), position_(position)
		{
			//piece_.assignToSquare(position_);
		};
		~TemporaryPiece()
		{
			piece_.isDead = true;
			position_.currentPiece = nullptr;
			//piece_.~Piece();
		};
		Piece get() { return piece_; };
		operator Piece() { return get(); };

	private:
		Piece& piece_;
		Square& position_;
	};

	class Game//: public QObject
	{
		//Q_OBJECT
	private:
		Board board;

		//Player p1;
		//Player p2;

		King k;
		King K;

		std::vector<Piece> pieces;

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
		char turn = 'B';
		Game()
		{
			board = Board();
			//p1 = Player(board, 'W');
			//p2 = Player(board, 'B');
			//initializePieces();
		}
		void makeMove(Square& currentPosition, Square& newPosition)
		{
			std::cout << "verifying correct move" << std::endl;
			std::cout << "my color is: " << turn << std::endl;
			std::cout << "the piece's color is: " << currentPosition.currentPiece->color_ << std::endl;
			if (currentPosition.currentPiece->color_ == turn)
			{
				std::cout << "right color" << std::endl;
				board.setPosition(currentPosition, newPosition);
			}
			else
			{
				std::cout << "wrong color" << std::endl;
			}
		}
		void initializePieces()
		{
			k = King('W');
			board.placePiece(std::make_shared<King>(k), Position{ 0,3 });
			K = King('B');
			board.placePiece(std::make_shared<King>(K), Position{7,3});
		}
		void play()
		{
			bool gameOver = false;

			int currentRow = 0;
			int currentColumn = 0;
			int newRow = 0;
			int newColumn = 0;

			std::cout << "game start" << std::endl;
			std::cout << "here are the current pieces on the board:" << std::endl;
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					if (board.squares[i][j]->currentPiece != nullptr)
					{
						std::cout << *board.squares[i][j];
					}
				}
			}
			while (!gameOver)
			{
				if ((k.isDead) || (K.isDead))
				{
					gameOver = true;
					break;
				}
				if (turn == 'W') { turn = 'B'; }
				else if (turn == 'B') { turn = 'W'; }
				std::cout << "current turn: " << turn << std::endl;
				if (turn == 'W') 
				{ 
					std::cout << "player 1: your turn. \nselect a piece on the board to move, one coordinate at a time \nexample, to access the piece at (3,0): \n 3 \n 0\n\n"; 
					std::cin >> currentRow;
					std::cin >> currentColumn;
					std::cout << "player 1: pick a destination location\n";
					std::cin >> newRow;
					std::cin >> newColumn;
					makeMove(*board.squares[currentRow][currentColumn], *board.squares[newRow][newColumn]);
				}
				else if (turn == 'B')
				{
					std::cout << "player 2: your turn. \nselect a piece on the board to move, one coordinate at a time \nexample, to access the piece at (3,0): \n 3 \n 0\n\n";
					std::cin >> currentRow;
					std::cin >> currentColumn;
					std::cout << "player 2: pick a destination location\n";
					std::cin >> newRow;
					std::cin >> newColumn;
					makeMove(*board.squares[currentRow][currentColumn], *board.squares[newRow][newColumn]);
				}
			}
			std::cout << "game over";
		}
	};
}
