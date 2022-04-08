//#pragma once
//#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
//#include <QObject>
//#pragma pop()
#include "Chess.hpp"
using namespace std;

class King : virtual public Piece
{
public:
	King(Board& board, char color) :Piece(board, color)
	{
		initializePosition();
	};
	virtual void initializePosition() override
	{
		switch (color_) 
		{
			case 'W':
				currentPosition = board_[0][4];
				board_[0][4]->currentPiece = make_shared<Piece>(*this);
				break;
			case 'B':
				currentPosition = board_[7][4];
				board_[7][4]->currentPiece = make_shared<Piece>(*this);
				break;
		}
	};
	//virtual void setPosition(shared_ptr<Square> newPosition) override { currentPosition = newPosition; };
	//virtual void updatePossiblePositions() override { possiblePositions.push_back(board_[7][4]); };
	void talk(ostream& os) const override
	{
		os << "hello i am the king. i am currently position (" << currentPosition->xAxis_ << " ," << currentPosition->yAxis_ << " ) \n";
	}
};

class Queen : public Piece
{
	//Queen() {};
	virtual void initializePosition()
	{
		switch (color_) {
		case 'W':
			currentPosition = board_[0][3];
			board_[0][3]->currentPiece = make_shared<Piece>(*this);
		case 'B':
			currentPosition = board_[7][3];
			board_[7][3]->currentPiece = make_shared<Piece>(*this);
		}
	};
	virtual void setPosition() {};
	virtual void updatePossiblePositions() {};
};

class Bishop : public Piece
{
	//Bishop() {};
	virtual void initializePosition() {};
	virtual void setPosition(){};
	virtual void updatePossiblePositions(){};
};

class Knight : public Piece 
{
	//Knight() {};
	virtual void initializePosition() {};
	virtual void setPosition() {};
	virtual void updatePossiblePositions() {};
};

class Rook : public Piece
{
	//Rook() {};
	virtual void initializePosition() {};
	virtual void setPosition() {};
	virtual void updatePossiblePositions(){};
};

class Pawn : public Piece 
{
	//Pawn() {};
	virtual void initializePosition() {};
	virtual void setPosition(){};
	virtual void updatePossiblePositions(){};
};