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
	void initializePosition() override
	{
		switch (color_) 
		{
			case 'W':
				currentPosition = board_.squares[0][4];
				assignToSquare(0, 4);
				break;
			case 'B':
				currentPosition = board_.squares[7][4];
				assignToSquare(7, 4);
				break;
		}
	};
	void assignToSquare(int X, int Y)
	{
		board_.squares[X][Y]->currentPiece = make_shared<King>(*this);
	}
	void updatePossiblePositions() override 
	{ 
		addPossiblePosition(currentPosition->xAxis_,currentPosition->yAxis_);
		addPossiblePosition(currentPosition->xAxis_+1, currentPosition->yAxis_);
		addPossiblePosition(currentPosition->xAxis_-1, currentPosition->yAxis_);
		addPossiblePosition(currentPosition->xAxis_, currentPosition->yAxis_+1);
		addPossiblePosition(currentPosition->xAxis_, currentPosition->yAxis_-1);
		addPossiblePosition(currentPosition->xAxis_+1, currentPosition->yAxis_+1);
		addPossiblePosition(currentPosition->xAxis_ - 1, currentPosition->yAxis_ - 1);
		addPossiblePosition(currentPosition->xAxis_ + 1, currentPosition->yAxis_ - 1);
		addPossiblePosition(currentPosition->xAxis_ - 1, currentPosition->yAxis_ + 1);
		
		//remove_if(possiblePositions.begin(), possiblePositions.end(), [*this](auto& position) { return position->currentPiece->color_ == color_; });

		cout << "my possible positions rn are:" << endl;
		for (auto&& position : possiblePositions)
		{
			cout << *position;
		}
	};
	void talk(ostream& os) const override
	{
		os << "hello i am the king. i am currently at position (" << currentPosition->xAxis_ << "," << currentPosition->yAxis_ << ") \n";
	}

private:

};

class Queen : public Piece
{
	//Queen() {};
	virtual void initializePosition()
	{
		switch (color_) {
		case 'W':
			currentPosition = board_.squares[0][3];
			board_.squares[0][3]->currentPiece = make_shared<Piece>(*this);
			break;
		case 'B':
			currentPosition = board_.squares[7][3];
			board_.squares[7][3]->currentPiece = make_shared<Piece>(*this);
			break;
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