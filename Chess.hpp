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
using namespace std;  // On le permet, mais j'ai écrit mon .hpp sans, avant de le permettre dans l'énoncé.


//#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
////#include <QObject>
//#pragma pop()

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
	shared_ptr<Piece> currentPiece = nullptr;
private:

};

class Piece //: public QObject
{
	//Q_OBJECT
public:
	//Piece() = default;
	virtual ~Piece() = default;

	Piece(Square& square, char color) :color_(color)
	{
	}
	//enum Direction{HORIZONTAL, VERTICAL, DIAGONAL};
	//virtual void initializePosition(int n = 0) { currentPosition = make_shared<Square>(n, n); };

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
				cout << "move is among the piece's possible positions" << endl;
			}
		}
		return valid;
	};
	virtual void talk(ostream& os) const { os << "plain piece"; };
	char color_ = 'W';
	void addPossiblePosition(int newX, int newY)
	{
		if ((newX <= 7) &&
			(newY <= 7) &&
			(newX >= 0) &&
			(newY >= 0))
		{
			possiblePositions.push_back(make_shared<Square>(newX, newY));
		}
	}
	list<shared_ptr<Square>> possiblePositions;
	bool isDead = false;
private:
};


ostream& operator<< (ostream& os, const Piece& piece)
{
	piece.talk(os);
	return os;
}

ostream& operator<< (ostream& os, const Square& square)
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
	Square squares[8][8];
	list<Piece> pieces;
	void populate()
	{
		for (int i = 0; i < 8; i++)
		{
			for (int k = 0; k < 8; k++)
			{
				squares[i][k] = Square(i, k);
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
				cout << *newPosition.currentPiece << " is dead" << endl;
				newPosition.currentPiece = nullptr;
			}
			currentPosition.currentPiece->assignToSquare(newPosition);
			currentPosition.currentPiece = nullptr;
			cout << "positions changed" << endl;
		}
		else
		{
			cout << "invalid move" << endl;
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
			{ return checkPositionOverlap(currentPosition,*pos); });
		cout << "possible positions:" << endl;
		for (auto&& position : currentPosition.currentPiece->possiblePositions)
		{
			cout << *position;
		}
		//TODO: verifier si parcours entre currentPosition et newPosition est libre
		return currentPosition.currentPiece->validateMove(newPosition);
	}
private:

};

class KingInstanceException : public logic_error
{
public:
	using logic_error::logic_error;
	
};
class King : public Piece
{
public:
	King(Square& square, char color) : Piece(square, color)
	{
		try
		{
			if (instanceCount_ == 2)
			{
				throw KingInstanceException("max instances reached\n");
			}
			else
			{
				assignToSquare(square);
				instanceCount_++;
			}
		}
		catch (KingInstanceException& e)//mettre dans une autre classe qui controle la vue = interface 
		{
			cout << e.what();
		}
	};
	~King()
	{
		instanceCount_--;
	};
	static int getCount() { return instanceCount_; }

	void assignToSquare(Square& square)
	{
		square.currentPiece = make_shared<King>(*this);
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
	void talk(ostream& os) const override
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
		square.currentPiece = make_shared<Rook>(*this);
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
	void talk(ostream& os) const override
	{
		os << "rook  (" << color_ << ")";
	}

private:
};
class Knight : public Piece
{
public:
	Knight(Square& square, char color) :Piece(square, color)
	{
		assignToSquare(square);
	};

	void assignToSquare(Square& square)
	{
		square.currentPiece = make_shared<Knight>(*this);
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
	void talk(ostream& os) const override
	{
		os << "knight (" << color_ << ")";
	}

private:
};

class Player
{
public:
	Player(Board& board, char color) :color_(color) { board_ = make_shared<Board>(board); };
	char color_;
	shared_ptr<Board> board_;
	void makeMove(Square& currentPosition, Square& newPosition)
	{
		if (currentPosition.currentPiece->color_ == color_)
		{
			board_->setPosition(currentPosition, newPosition);
		}
		else
		{
			cout << "wrong color" << endl;
		}
	}
private:
};
class TemporaryMove
{
public:
	TemporaryMove(Board& board, Square& startingPosition, Square& newPosition) :board_(board), start_(startingPosition), end_(newPosition)
	{
		board_.setPosition(start_, end_);
	};
	~TemporaryMove()
	{
		end_.currentPiece->isDead = true;
		end_.currentPiece = nullptr;

		//board_.setPosition(end_, start_);
	};
private:
	Board& board_;
	Square& start_;
	Square& end_;
};