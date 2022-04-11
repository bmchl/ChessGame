//#pragma once
//#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
//#include <QObject>
//#pragma pop()
#include "Chess.hpp"
using namespace std;

class King :  public Piece
{
public:
	King(Board& board, char color) :Piece(board, color)
	{
		initializePosition();
	};
	void initializePosition(int n = 0) override
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
	bool isValidMove(shared_ptr<Square> position)
	{
		bool valid = false;
		for (auto& possiblePosition : possiblePositions)
		{
			if ((position->row_ == possiblePosition->row_) &&
				(position->column_ == possiblePosition->column_))
			{
				valid = true;
				cout << "ok your move is among the piece's possible positions good job" << endl;
			}
		}
		return valid;
	};
	void updatePossiblePositions() override 
	{ 
		addPossiblePosition(currentPosition->row_,currentPosition->column_);
		addPossiblePosition(currentPosition->row_+1, currentPosition->column_);
		addPossiblePosition(currentPosition->row_-1, currentPosition->column_);
		addPossiblePosition(currentPosition->row_, currentPosition->column_+1);
		addPossiblePosition(currentPosition->row_, currentPosition->column_-1);
		addPossiblePosition(currentPosition->row_+1, currentPosition->column_+1);
		addPossiblePosition(currentPosition->row_ - 1, currentPosition->column_ - 1);
		addPossiblePosition(currentPosition->row_ + 1, currentPosition->column_ - 1);
		addPossiblePosition(currentPosition->row_ - 1, currentPosition->column_ + 1);
		possiblePositions.remove_if([this](auto& pos)
			{ return checkPositionOverlap(pos); });
		cout << "my possible positions rn are:" << endl;
		for (auto&& position : possiblePositions)
		{
			cout << *position;
		}
	};
	void talk(ostream& os) const override
	{
		os << "hello i am the king. i am currently at position (" << currentPosition->row_ << "," << currentPosition->column_ << ") \n";
	}

private:

};

class Queen :  public Piece
{
public:
	Queen(Board& board, char color) :Piece(board, color)
	{
		initializePosition();
	};
	void initializePosition(int n = 0) override
	{
		switch (color_)
		{
		case 'W':
			currentPosition = board_.squares[0][3];
			assignToSquare(0, 3);
			break;
		case 'B':
			currentPosition = board_.squares[7][3];
			assignToSquare(7, 3);
			break;
		}
	};
	void assignToSquare(int X, int Y)
	{
		board_.squares[X][Y]->currentPiece = make_shared<Queen>(*this);
	}

	bool isValidMove(shared_ptr<Square> newPosition) override
	{
		if (checkPositionOverlap(newPosition))
		{
			return false;
		}
		bool valid = true;
		//vertical move
		if ((currentPosition->row_ == newPosition->row_) && (currentPosition->column_ != newPosition->column_))
		{
			// moving upwards
			if (currentPosition->column_ < newPosition->column_)
			{
				valid = true;
				for (int i = (currentPosition->column_ + 1); i < newPosition->column_; i++)
				{
					if (board_.squares[currentPosition->row_][i]->currentPiece!=nullptr)
					{
						valid = false;
						cout << "vertical path to the right is not clear\n";
					}
				}
			}
			// moving downwards
			else if (currentPosition->column_ > newPosition->column_)
			{
				valid = true;
				for (int i = (currentPosition->column_ - 1); i > newPosition->column_; i--)
				{
					if (board_.squares[currentPosition->row_][i]->currentPiece != nullptr)
					{
						valid = false;
						cout << "Horizontal path to the left is not clear!\n";
					}
				}
			}
			else { valid = false; }
		}
		// horizontal move
		else if ((currentPosition->row_ != newPosition->row_) && (currentPosition->column_ == newPosition->column_))
		{
			// moving to the right
			if (currentPosition->row_ < newPosition->row_)
			{
				valid = true;
				for (int i = (currentPosition->row_ + 1); i < newPosition->row_; i++)
				{
					if (board_.squares[i][currentPosition->column_]->currentPiece != nullptr)
					{
						valid = false;
						cout << "horizontal path to the right is not clear\n";
					}
				}
			}
			// Moving to the left
			else if (currentPosition->row_ > newPosition->row_)
			{
				valid = true;
				for (int i = (currentPosition->row_ - 1); i > newPosition->row_; i--)
				{
					if (board_.squares[i][currentPosition->column_]->currentPiece != nullptr)
					{
						valid = false;
						cout << "horizontal path to the left is not clear\n";
					}
				}
			}
			else { valid = false; }
		}
		// diagonal move
		else if (abs(newPosition->row_ - currentPosition->row_) == abs(newPosition->column_ - currentPosition->column_))
		{
			// Moving up and right
			if ((newPosition->row_ > currentPosition->row_) && (newPosition->column_ > currentPosition->column_))
			{
				// Settting bFree as initially true, only inside the cases, guarantees that the path is checked
				valid = true;

				for (int i = 1; i < abs(newPosition->row_ - currentPosition->row_); i++)
				{
					if (board_.squares[currentPosition->row_ + i][currentPosition->column_ + i]->currentPiece != nullptr)					{
						valid = false;
						cout << "Diagonal path up-right is not clear!\n";
					}
				}
			}

			// Moving down and right
			else if ((newPosition->row_ > currentPosition->row_) && (newPosition->column_ < currentPosition->column_))
			{
				// Settting bFree as initially true, only inside the cases, guarantees that the path is checked
				valid = true;
				for (int i = 1; i < abs(newPosition->row_ - currentPosition->row_); i++)
				{
					if (board_.squares[currentPosition->row_ + i][currentPosition->column_ - i]->currentPiece != nullptr) {
						valid = false;
						cout << "Diagonal path down-right is not clear!\n";
					}
				}
			}

			// Moving up and left
			else if ((newPosition->row_ < currentPosition->row_) && (newPosition->column_ > currentPosition->column_))
			{
				// Settting bFree as initially true, only inside the cases, guarantees that the path is checked
				valid = true;

				for (int i = 1; i < abs(newPosition->row_ - currentPosition->row_); i++)
				{
					if (board_.squares[currentPosition->row_ - i][currentPosition->column_ + i]->currentPiece != nullptr) {
						valid = false;
						cout << "Diagonal path up-left is not clear!\n";
					}
				}
			}

			// Moving down and left
			else if ((newPosition->row_ < currentPosition->row_) && (newPosition->column_ < currentPosition->column_))
			{
				// Settting bFree as initially true, only inside the cases, guarantees that the path is checked
				valid = true;
				for (int i = 1; i < abs(newPosition->row_ - currentPosition->row_); i++)
				{
					if (board_.squares[currentPosition->row_ - i][currentPosition->column_ - i]->currentPiece != nullptr) {
						valid = false;
						cout << "Diagonal path down-left is not clear!\n";
					}
				}
			}

			else
			{
				valid = false;
			}
		}
		else { valid = false; }
		return valid;
	}
	void updatePossiblePositions() override
	{
	};
	void talk(ostream& os) const override
	{
		os << "hello i am the queen. i am currently at position (" << currentPosition->row_ << "," << currentPosition->column_ << ") \n";
	}

private:
};

class Bishop :  public Piece
{
public:
	Bishop(Board& board, char color, int n) :Piece(board, color)
	{
		initializePosition(n);
	};
	void initializePosition(int n = 0) override
	{
		switch (color_)
		{
		case 'W':
			currentPosition = board_.squares[0][n];
			assignToSquare(0, n);
			break;
		case 'B':
			currentPosition = board_.squares[7][n];
			assignToSquare(7, n);
			break;
		}
	};
	void assignToSquare(int X, int Y)
	{
		board_.squares[X][Y]->currentPiece = make_shared<Bishop>(*this);
	}

	bool isValidMove(shared_ptr<Square> newPosition) override
	{
		if (checkPositionOverlap(newPosition))
		{
			return false;
		}
		bool valid = true;
		// diagonal move
		if (abs(newPosition->row_ - currentPosition->row_) == abs(newPosition->column_ - currentPosition->column_))
		{
			// Moving up and right
			if ((newPosition->row_ > currentPosition->row_) && (newPosition->column_ > currentPosition->column_))
			{
				// Settting bFree as initially true, only inside the cases, guarantees that the path is checked
				valid = true;

				for (int i = 1; i < abs(newPosition->row_ - currentPosition->row_); i++)
				{
					if (board_.squares[currentPosition->row_ + i][currentPosition->column_ + i]->currentPiece != nullptr) {
						valid = false;
						cout << "Diagonal path up-right is not clear!\n";
					}
				}
			}

			// Moving down and right
			else if ((newPosition->row_ > currentPosition->row_) && (newPosition->column_ < currentPosition->column_))
			{
				// Settting bFree as initially true, only inside the cases, guarantees that the path is checked
				valid = true;
				for (int i = 1; i < abs(newPosition->row_ - currentPosition->row_); i++)
				{
					if (board_.squares[currentPosition->row_ + i][currentPosition->column_ - i]->currentPiece != nullptr) {
						valid = false;
						cout << "Diagonal path down-right is not clear!\n";
					}
				}
			}

			// Moving up and left
			else if ((newPosition->row_ < currentPosition->row_) && (newPosition->column_ > currentPosition->column_))
			{
				// Settting bFree as initially true, only inside the cases, guarantees that the path is checked
				valid = true;

				for (int i = 1; i < abs(newPosition->row_ - currentPosition->row_); i++)
				{
					if (board_.squares[currentPosition->row_ - i][currentPosition->column_ + i]->currentPiece != nullptr) {
						valid = false;
						cout << "Diagonal path up-left is not clear!\n";
					}
				}
			}

			// Moving down and left
			else if ((newPosition->row_ < currentPosition->row_) && (newPosition->column_ < currentPosition->column_))
			{
				// Settting bFree as initially true, only inside the cases, guarantees that the path is checked
				valid = true;
				for (int i = 1; i < abs(newPosition->row_ - currentPosition->row_); i++)
				{
					if (board_.squares[currentPosition->row_ - i][currentPosition->column_ - i]->currentPiece != nullptr) {
						valid = false;
						cout << "Diagonal path down-left is not clear!\n";
					}
				}
			}

			else
			{
				valid = false;
			}
		}
		else { valid = false; }
		return valid;
	}
	void updatePossiblePositions() override
	{
	};
	void talk(ostream& os) const override
	{
		os << "hello i am a bishop. i am currently at position (" << currentPosition->row_ << "," << currentPosition->column_ << ") \n";
	}

private:
};

class Rook :  public Piece
{
public:
	Rook(Board& board, char color, int n) :Piece(board, color)
	{
		initializePosition(n);
	};
	void initializePosition(int n = 0) override
	{
		switch (color_)
		{
		case 'W':
			currentPosition = board_.squares[0][n];
			assignToSquare(0, n);
			break;
		case 'B':
			currentPosition = board_.squares[7][n];
			assignToSquare(7, n);
			break;
		}
	};
	void assignToSquare(int X, int Y)
	{
		board_.squares[X][Y]->currentPiece = make_shared<Rook>(*this);
	}

	bool isValidMove(shared_ptr<Square> newPosition) override
	{
		if (checkPositionOverlap(newPosition))
		{
			return false;
		}
		bool valid = true;
		//vertical move
		if ((currentPosition->row_ == newPosition->row_) && (currentPosition->column_ != newPosition->column_))
		{
			// moving upwards
			if (currentPosition->column_ < newPosition->column_)
			{
				valid = true;
				for (int i = (currentPosition->column_ + 1); i < newPosition->column_; i++)
				{
					if (board_.squares[currentPosition->row_][i]->currentPiece != nullptr)
					{
						valid = false;
						cout << "vertical path to the right is not clear\n";
					}
				}
			}
			// moving downwards
			else if (currentPosition->column_ > newPosition->column_)
			{
				valid = true;
				for (int i = (currentPosition->column_ - 1); i > newPosition->column_; i--)
				{
					if (board_.squares[currentPosition->row_][i]->currentPiece != nullptr)
					{
						valid = false;
						cout << "Horizontal path to the left is not clear!\n";
					}
				}
			}
			else { valid = false; }
		}
		// horizontal move
		else if ((currentPosition->row_ != newPosition->row_) && (currentPosition->column_ == newPosition->column_))
		{
			// moving to the right
			if (currentPosition->row_ < newPosition->row_)
			{
				valid = true;
				for (int i = (currentPosition->row_ + 1); i < newPosition->row_; i++)
				{
					if (board_.squares[i][currentPosition->column_]->currentPiece != nullptr)
					{
						valid = false;
						cout << "horizontal path to the right is not clear\n";
					}
				}
			}
			// Moving to the left
			else if (currentPosition->row_ > newPosition->row_)
			{
				valid = true;
				for (int i = (currentPosition->row_ - 1); i > newPosition->row_; i--)
				{
					if (board_.squares[i][currentPosition->column_]->currentPiece != nullptr)
					{
						valid = false;
						cout << "horizontal path to the left is not clear\n";
					}
				}
			}
			else { valid = false; }
		}
		else { valid = false; }
		return valid;
	}
	void updatePossiblePositions() override
	{
	};
	void talk(ostream& os) const override
	{
		os << "hello i am a rook. i am currently at position (" << currentPosition->row_ << "," << currentPosition->column_ << ") \n";
	}

private:
};

class Knight :  public Piece
{
public:
	Knight(Board& board, char color, int n) :Piece(board, color)
	{
		initializePosition(n);
	};
	void initializePosition(int n = 0) override
	{
		switch (color_)
		{
		case 'W':
			currentPosition = board_.squares[0][n];
			assignToSquare(0, n);
			break;
		case 'B':
			currentPosition = board_.squares[7][n];
			assignToSquare(7, n);
			break;
		}
	};
	void assignToSquare(int X, int Y)
	{
		board_.squares[X][Y]->currentPiece = make_shared<Knight>(*this);
	}

	bool isValidMove(shared_ptr<Square> newPosition) override
	{
		if (checkPositionOverlap(newPosition))
		{
			return false;
		}
		bool valid = true;
		if ((2 == abs(newPosition->row_ - currentPosition->row_)) && (1 == abs(newPosition->column_ - currentPosition->column_)))
		{
			valid = true;
		}

		else if ((1 == abs(newPosition->row_ - currentPosition->row_)) && (2 == abs(newPosition->column_ - currentPosition->column_)))
		{
			valid = true;
		}
		else { valid = false; }
		return valid;
	}
	void updatePossiblePositions() override
	{
	};
	void talk(ostream& os) const override
	{
		os << "hello i am a knight. i am currently at position (" << currentPosition->row_ << "," << currentPosition->column_ << ") \n";
	}

private:
};

class Pawn :  public Piece
{
public:
	Pawn(Board& board, char color, int n) :Piece(board, color)
	{
		initializePosition(n);
	};
	void initializePosition(int n = 0) override
	{
		switch (color_)
		{
		case 'W':
			currentPosition = board_.squares[1][n];
			assignToSquare(1, n);
			break;
		case 'B':
			currentPosition = board_.squares[6][n];
			assignToSquare(6, n);
			break;
		}
		initialPosition = currentPosition;
	};

	void assignToSquare(int X, int Y)
	{
		board_.squares[X][Y]->currentPiece = make_shared<Pawn>(*this);
	}
	//TODO: pawns capture pieces diagonally, so figure that out
	bool isValidMove(shared_ptr<Square> newPosition) override
	{
		if (checkPositionOverlap(newPosition))
		{
			return false;
		}
		bool valid = true;
		if (newPosition->column_ == currentPosition->column_)
		{
			// Simple move forward
			if (((color_ == 'W') && newPosition->row_ == currentPosition->row_ + 1) ||
				((color_ == 'B') && (newPosition->row_ == currentPosition->row_ - 1)))
			{
				valid = true;
			}

			// Double move forward
			else if (((color_ == 'W') && (newPosition->row_ == currentPosition->row_ + 2)) ||
				((color_ == 'B') && (newPosition->row_ == currentPosition->row_ - 2)))
			{
				// This is only allowed if the pawn is in its original place
				if (currentPosition->row_ == initialPosition->row_ && currentPosition->column_ == initialPosition->column_)
				{
					valid = true;
				}
			}
			else
			{
				// This is invalid
				return false;
			}
		}
		return valid;
	}
	void updatePossiblePositions() override
	{
	};
	void talk(ostream& os) const override
	{
		os << "hello i am a pawn. i am currently at position (" << currentPosition->row_ << "," << currentPosition->column_ << ") \n";
	}

private:
	shared_ptr<Square> initialPosition;
};