#include "Rook.h"

void Rook::talk(std::ostream& os) const
{
	os << "rook  (" << color_ << ")";
}
void Rook::setIconPath() 
{
	if (color_ == 'W')
		{
			iconPath = "./img/wrook.png";
		}
	else if (color_ == 'B')
		{
			iconPath = "./img/brook.png";
		}
}
