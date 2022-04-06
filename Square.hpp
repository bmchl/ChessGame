#pragma once

#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QObject>
#pragma pop()
#include <functional>
#include "Chess.hpp"

using namespace std;

class Square : public QObject
{
	Q_OBJECT
public:
	Square(int x, int y) : xAxis_(x), yAxis_(y) {};
	void populateBoard(Board* board) { maxCoordinates_ = board->size - 1; };
	Piece* currentPiece;
private:
	int xAxis_ = 0;
	int yAxis_ = 0;
	int maxCoordinates_ = 7;
};