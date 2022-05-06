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
