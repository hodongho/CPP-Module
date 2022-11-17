#include "Weapon.hpp"

Weapon::Weapon(std::string _type)
{
	setType(_type);
}

std::string const &Weapon::getType()
{
	return (type);
}

void	Weapon::setType(std::string _type)
{
	type = _type;
}
