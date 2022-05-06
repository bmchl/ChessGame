#include "Square.hpp"


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