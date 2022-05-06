#include "Knight.h"

void Knight::talk(std::ostream& os) const
{
	os << "knight (" << color_ << ")";
}
void Knight::setIconPath()
{
	if (color_ == 'W')
		{
			iconPath = "./img/wknight.png";
		}
	else if (color_ == 'B')
		{
			iconPath = "./img/bknight.png";
		}
}