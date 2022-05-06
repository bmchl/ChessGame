#include "King.h"

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
