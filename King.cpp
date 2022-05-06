#include "King.hpp"

King::King(char color) :Piece(color)
{
	setIconPath();
	if (instanceCount_ >= 2)
	{
		throw KingInstanceException("max instances reached\n");
	}
	instanceCount_++;
	std::cout << "created new " << *this << std::endl;
}
King::~King()
{
	std::cout << "destroying " << *this << std::endl;
	instanceCount_--;
}
void King::talk(std::ostream& os) const
{
	os << "king (" << color_ << ")";
}
void King:: setIconPath() 
{
	if (color_ == 'W')
		{
			iconPath = "./img/wking.png";
		}
	else if (color_ == 'B')
		{
			iconPath = "./img/bking.png";
		}
}
