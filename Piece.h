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
#include "Square.h"

#pragma warning(push, 0) // Sinon Qt fait des avertissements ‡ /W4.
#include <QObject>
#include <QString>
#pragma pop()

class Piece //: public QObject
{
	//Q_OBJECT
public:
	Piece() = default;
		virtual ~Piece() = default;
			QString iconPath = "";
			virtual void setIconPath() {};
			Piece(char color) : color_(color) {};
			/*Piece(Square& square, char color) : color_(color)
			{
			}*/
			//virtual void assignToSquare(Square& square) {};
			virtual void updatePossiblePositions(Position& position) {};
			bool validateMove(Position& position);
			virtual void talk(std::ostream& os) const;
			char color_ = 'W';
			/*void clearPossiblePositions()
			{
			while (!possiblePositions.empty())
			{
			delete possiblePositions.front(), possiblePositions.pop_front();
			}
			}*/
			void addPossiblePosition(int newX, int newY);
			std::list<Position*> possiblePositions;
			bool isDead = false;
		private:
};

