#pragma once
#include <string>
#include <iostream>
#include <memory>
#include <functional>
#include <cassert>
#include <iterator>
//#include "gsl/span"
#include <vector>
#include <list>
//using gsl::span;
//using namespace std;  // On le permet, mais j'ai écrit mon .hpp sans, avant de le permettre dans l'énoncé.


//#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
////#include <QObject>
//#pragma pop()
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
		int row_ = 0;
		int column_ = 0;
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

		Piece(Square& square, char color) : color_(color)
		{
		}
		virtual void assignToSquare(Square& square) {};
		virtual void updatePossiblePositions(Square& position) {};
		bool validateMove(Square& position)
		{
			bool valid = false;
			for (auto& possiblePosition : possiblePositions)
			{
				if ((position.row_ == possiblePosition->row_) &&
					(position.column_ == possiblePosition->column_))
				{
					valid = true;
					std::cout << "move is among the piece's possible positions" << std::endl;
					clearPossiblePositions();
				}
			}
			return valid;
		};
		virtual void talk(std::ostream& os) const { os << "plain piece"; };
		char color_ = 'W';
		void clearPossiblePositions()
		{
			while (!possiblePositions.empty())
			{
				delete possiblePositions.front(), possiblePositions.pop_front();
			}
		}
		void addPossiblePosition(int newX, int newY)
		{
			if ((newX <= 7) &&
				(newY <= 7) &&
				(newX >= 0) &&
				(newY >= 0))
			{
				possiblePositions.push_back(new Square(newX, newY));
			}
		}
		std::list<Square*> possiblePositions;
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
					squares[i][k] = std::make_unique<Square>(i, k);
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
				currentPosition.currentPiece->assignToSquare(newPosition);
				currentPosition.currentPiece = nullptr;
				std::cout << "positions changed" << std::endl;
			}
			else
			{
				std::cout << "invalid move" << std::endl;
			}
		};
		/*void capturePiece(Square& position)
		{
			position.currentPiece->isDead = true;
			position.currentPiece = nullptr;
		}*/
		bool isValidMove(Square& currentPosition, Square& newPosition)
		{
			currentPosition.currentPiece->updatePossiblePositions(currentPosition);
			currentPosition.currentPiece->possiblePositions.remove_if([this, &currentPosition](auto& pos)
				{ return checkPositionOverlap(currentPosition, *pos); });
			std::cout << "possible positions:" << std::endl;
			for (auto&& position : currentPosition.currentPiece->possiblePositions)
			{
				std::cout << *position;
			}
			//TODO: verifier si parcours entre currentPosition et newPosition est libre
			return currentPosition.currentPiece->validateMove(newPosition);
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
		King(Square& square, char color) : Piece(square, color)
		{
			if (instanceCount_ >= 2)
			{
				throw KingInstanceException("max instances reached\n");
			}
			assignToSquare(square);
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

		void assignToSquare(Square& square)
		{
			square.currentPiece = std::make_shared<King>(*this);
		}

		void updatePossiblePositions(Square& currentPosition) override
		{
			addPossiblePosition(currentPosition.row_, currentPosition.column_);
			addPossiblePosition(currentPosition.row_ + 1, currentPosition.column_);
			addPossiblePosition(currentPosition.row_ - 1, currentPosition.column_);
			addPossiblePosition(currentPosition.row_, currentPosition.column_ + 1);
			addPossiblePosition(currentPosition.row_, currentPosition.column_ - 1);
			addPossiblePosition(currentPosition.row_ + 1, currentPosition.column_ + 1);
			addPossiblePosition(currentPosition.row_ - 1, currentPosition.column_ - 1);
			addPossiblePosition(currentPosition.row_ + 1, currentPosition.column_ - 1);
			addPossiblePosition(currentPosition.row_ - 1, currentPosition.column_ + 1);
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
		Rook(Square& square, char color) :Piece(square, color)
		{
			assignToSquare(square);
		};

		void assignToSquare(Square& square)
		{
			square.currentPiece = std::make_shared<Rook>(*this);
		}
		void updatePossiblePositions(Square& currentPosition) override
		{
			for (int i = 1; i < 7; i++)
			{
				addPossiblePosition(currentPosition.row_, currentPosition.column_ + i);
				addPossiblePosition(currentPosition.row_, currentPosition.column_ - i);
				addPossiblePosition(currentPosition.row_ + i, currentPosition.column_);
				addPossiblePosition(currentPosition.row_ - i, currentPosition.column_);
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
		Knight(Square& square, char color) : Piece(square, color)
		{
			assignToSquare(square);
		};

		void assignToSquare(Square& square)
		{
			square.currentPiece = std::make_shared<Knight>(*this);
		}

		void updatePossiblePositions(Square& currentPosition) override
		{
			addPossiblePosition(currentPosition.row_ + 1, currentPosition.column_ + 2);
			addPossiblePosition(currentPosition.row_ + 2, currentPosition.column_ + 1);
			addPossiblePosition(currentPosition.row_ - 1, currentPosition.column_ - 2);
			addPossiblePosition(currentPosition.row_ - 2, currentPosition.column_ - 1);

			addPossiblePosition(currentPosition.row_ + 1, currentPosition.column_ - 2);
			addPossiblePosition(currentPosition.row_ + 2, currentPosition.column_ - 1);
			addPossiblePosition(currentPosition.row_ - 1, currentPosition.column_ + 2);
			addPossiblePosition(currentPosition.row_ - 2, currentPosition.column_ + 1);
		};
		void talk(std::ostream& os) const override
		{
			os << "knight (" << color_ << ")";
		}

	private:
	};

	class Player
	{
	public:
		Player() = default;// { board_ = Board(); };
		Player(Board& board, char color) : board_(&board), color_(color) {  };
		Player operator = (const Player& p) { return Player(*p.board_, p.color_); }
		char color_;
		void makeMove(Square& currentPosition, Square& newPosition)
		{
			std::cout << "verifying correct move" << std::endl;
			if (currentPosition.currentPiece->color_ == color_)
			{
				std::cout << "right color" << std::endl;
				board_->setPosition(currentPosition, newPosition);
			}
			else
			{
				std::cout << "wrong color" << std::endl;
			}
		}
	private:
		Board* board_;
	};

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

	class Game
	{
	private:
		Board board;

		Player p1;
		Player p2;

		King k;
		King K;

	public:
		Game()
		{
			board = Board();
			p1 = Player(board, 'W');
			p2 = Player(board, 'B');
		}
		void initializePieces()
		{
			k = King(*board.squares[0][3], 'W');
			k = King(*board.squares[7][3], 'B');
		}
		void play()
		{
			bool gameOver = false;
			char turn = 'B';

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
					p1.makeMove(*board.squares[currentRow][currentColumn], *board.squares[newRow][newColumn]);
				}
				else if (turn == 'B')
				{
					std::cout << "player 2: your turn. \nselect a piece on the board to move, one coordinate at a time \nexample, to access the piece at (3,0): \n 3 \n 0\n\n";
					std::cin >> currentRow;
					std::cin >> currentColumn;
					std::cout << "player 2: pick a destination location\n";
					std::cin >> newRow;
					std::cin >> newColumn;
					p2.makeMove(*board.squares[currentRow][currentColumn], *board.squares[newRow][newColumn]);
				}
			}
			std::cout << "game over";
		}
	};

	/*struct Position {
		int row = 0;
		int column = 0;
	};*/
}
