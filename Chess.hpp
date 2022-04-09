#pragma once
#include <string>
#include <iostream>
#include <memory>
#include <functional>
#include <cassert>
#include <iterator>
#include "gsl/span"
#include <vector>
#include <list>
using gsl::span;
using namespace std;  // On le permet, mais j'ai écrit mon .hpp sans, avant de le permettre dans l'énoncé.


//#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
////#include <QObject>
//#pragma pop()

class Board; 
class Square;
class Piece;

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
		//squares = make_unique< shared_ptr<Square>>[size][size] = 0;
	};
	shared_ptr<Square> squares[8][8];
	//vector<shared_ptr<Square>> vectorSquares;
	void populate()
	{
		for (int i = 0; i < 8; i++)
		{
			for (int k = 0; k < 8; k++)
			{
				//squares[i][k] = make_shared<Square>(i, k);

				//shared_ptr<Square> newSquare = make_shared<Square>(i, k);
				squares[i][k] = make_shared<Square>(i, k);
			}
		}
	}
	/*vector<shared_ptr<Square>> operator[](int x)
	{
		vector<shared_ptr<Square>>::const_iterator first = vectorSquares.cbegin() + (x * size);
		vector<shared_ptr<Square>>::const_iterator last = vectorSquares.cbegin() + x * size + size;
		vector<shared_ptr<Square>> subSquares(first, last);
		return subSquares;
	}*/
private:

};

class Square //:public QObject
{
	//Q_OBJECT
public:
	Square(int x, int y) : xAxis_(x), yAxis_(y) {};
	//void populateBoard(Board& board) { maxCoordinates_ = board.size - 1; };
	//Piece* currentPiece;
	//friend ostream& operator<< (ostream& os, const Square& square);
	int xAxis_ = 0;
	int yAxis_ = 0;
	int maxCoordinates_ = 7;
	shared_ptr<Piece> currentPiece = nullptr;
private:

};
ostream& operator<< (ostream& os, const Square& square)
{
	os << "i am a square at position ( " << square.xAxis_ << ", " << square.yAxis_ << " ) \n";
	return os;
}

class Piece //: public QObject
{
	//Q_OBJECT
public:
	//Piece() = default;
	Piece(Board& board, char color) :board_(board), color_(color)
	{
		initializePosition();
	}
	virtual void initializePosition() { currentPosition = make_shared<Square>(0, 0); };
	virtual void setPosition(shared_ptr<Square> newPosition)
	{
		updatePossiblePositions();
		if (isValidMove(newPosition))
		{
			board_.squares[currentPosition->xAxis_][currentPosition->yAxis_]->currentPiece = nullptr;
			currentPosition = newPosition;

			if (board_.squares[newPosition->xAxis_][newPosition->yAxis_]->currentPiece != nullptr)
			{
				//cout << *board_.squares[newPosition->xAxis_][newPosition->yAxis_]->currentPiece;
				cout << "i'm dead now" << endl;
			}

			assignToSquare(newPosition->xAxis_, newPosition->yAxis_);
			cout << "switchin them positions for you <3" << endl;

		}
		else
		{
			cout << "invalid move sus try again" << endl;
		}
	};
	virtual void assignToSquare(int X, int Y) {};
	virtual void updatePossiblePositions() {};
	virtual bool isValidMove(shared_ptr<Square> position) 
	{
		bool valid = false;
		for (auto& possiblePosition : possiblePositions)
		{
			if ((position->xAxis_ == possiblePosition->xAxis_) &&
				(position->yAxis_ == possiblePosition->yAxis_))
			{
				valid = true;
			}
		}
		return valid;
	};
	virtual void talk(ostream& os) const { os << "just a plain piece tbh"; };
	char color_ = 'W';
	void addPossiblePosition(int newX, int newY)
	{
		if ((newX <= board_.max) &&
			(newY <= board_.max) &&
			(newX >= 0) &&
			(newY >= 0))
		{
			possiblePositions.push_back(board_.squares[newX][newY]);
		}
	}
protected:
	Board& board_;
	shared_ptr<Square> currentPosition;
	vector<shared_ptr<Square>> possiblePositions;
};

ostream& operator<< (ostream& os, const Piece& piece)
{
	piece.talk(os);
	return os;
}