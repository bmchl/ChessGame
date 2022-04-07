#pragma once
#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QObject>
#pragma pop()
#include "Chess.hpp"
using namespace std;

class Piece : public QObject
{
	Q_OBJECT
public:
	virtual void initializePosition() = 0;
	virtual void setPosition(Square* newPosition) = 0;
	virtual void updatePossiblePositions() = 0;
	virtual void checkValidMove(Square* position) {};
protected:
	char color = 'W';
	Square* currentPosition;
	vector<Square*> possiblePositions;
};

class King : public Piece
{
public:
	King() {};
	virtual void initializePosition() {};
	virtual void setPosition() {};
	virtual void updatePossiblePositions(){};
};

class Queen : public Piece
{
	Queen() {};
	virtual void initializePosition() {}
	virtual void setPosition() {};
	virtual void updatePossiblePositions() {};
};

class Bishop : public Piece
{
	Bishop() {};
	virtual void initializePosition() {};
	virtual void setPosition(){};
	virtual void updatePossiblePositions(){};
};

class Knight : public Piece 
{
	Knight() {};
	virtual void initializePosition() {};
	virtual void setPosition() {};
	virtual void updatePossiblePositions() {};
};

class Rook : public Piece
{
	Rook() {};
	virtual void initializePosition() {};
	virtual void setPosition() {};
	virtual void updatePossiblePositions(){};
};

class Pawn : public Piece 
{
	Pawn() {};
	virtual void initializePosition() {};
	virtual void setPosition(){};
	virtual void updatePossiblePositions(){};
};