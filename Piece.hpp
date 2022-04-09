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
				currentPosition = board_[0][4];
				board_[0][4]->currentPiece = make_shared<King>(*this);
				break;
			case 'B':
				currentPosition = board_[7][4];
				board_[7][4]->currentPiece = make_shared<King>(*this);
				break;
		}
	};
	//virtual void setPosition(shared_ptr<Square> newPosition) override { currentPosition = newPosition; };
	void updatePossiblePositions() override 
	{ 
	//	possiblePositions.push_back(board_[currentPosition->xAxis_][currentPosition->yAxis_]);
	//	possiblePositions.push_back(board_[currentPosition->xAxis_ + 1][currentPosition->yAxis_]);
	//	possiblePositions.push_back(board_[currentPosition->xAxis_ + - 1][currentPosition->yAxis_]);
	//	possiblePositions.push_back(board_[currentPosition->xAxis_][currentPosition->yAxis_ + 1]);
	//	possiblePositions.push_back(board_[currentPosition->xAxis_][currentPosition->yAxis_ - 1]);
	//	possiblePositions.push_back(board_[currentPosition->xAxis_+ 1][currentPosition->yAxis_ + 1]);
	//	possiblePositions.push_back(board_[currentPosition->xAxis_ - 1][currentPosition->yAxis_ - 1]);
	//	possiblePositions.push_back(board_[currentPosition->xAxis_ + 1][currentPosition->yAxis_ - 1]);
	//	possiblePositions.push_back(board_[currentPosition->xAxis_ - 1][currentPosition->yAxis_ + 1]);
		
		//remove_if(possiblePositions.begin(), possiblePositions.end(), [*this](auto& position) { return position->currentPiece->color_ == color_; });

		//remove_if(possiblePositions.begin(), possiblePositions.end(), 
		//	[*this](auto& position) 
		//	{ 
		//	return ((position->xAxis_ > position->maxCoordinates_) ||
		//			(position->yAxis_ > position->maxCoordinates_) ||
		//			(position->xAxis_ < 0) ||
		//			(position->yAxis_ < 0));
		//	});

		//cout << "my possible positions rn are:" << endl;
		//for (auto&& position : possiblePositions)
		//{
		//	cout << "(" << position->xAxis_ << "," << position->xAxis_ << ")" << endl;
		//}
	};
	void talk(ostream& os) const override
	{
		os << "hello i am the king. i am currently at position (" << currentPosition->xAxis_ << " ," << currentPosition->yAxis_ << " ) \n";
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