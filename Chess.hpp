#pragma once
#include <string>
#include <iostream>
#include <memory>
#include <functional>
#include <cassert>
#include <iterator>
#include "gsl/span"
#include <vector>
using gsl::span;
using namespace std;  // On le permet, mais j'ai écrit mon .hpp sans, avant de le permettre dans l'énoncé.


//#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
////#include <QObject>
//#pragma pop()

class Board; 
class Square;

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

private:

};
ostream& operator<< (ostream& os, const Square& square)
{
	os << "i am a square at position ( " << square.xAxis_ << ", " << square.yAxis_ << " ) \n";
	return os;
}
class Board //: public QObject
{
	//Q_OBJECT
public:
	int size = 8;
	Board(int size) :size(size) { populate(); };
	vector<Square*> squares;
	void populate()
	{
		for (int i = 0; i < size; i++)
		{
			for (int k = 0; k < size; k++)
			{
				Square* newSquare = new Square(i, k);
				squares.push_back(newSquare);
			}
		}
	}
	vector<Square*>& operator[](int x)
	{
		vector<Square*>::const_iterator first = squares.cbegin() + (x * size);
		vector<Square*>::const_iterator last = squares.cbegin() + x * size + size;
		vector<Square*> subSquares(first, last);
		return subSquares;
	}
private:

};