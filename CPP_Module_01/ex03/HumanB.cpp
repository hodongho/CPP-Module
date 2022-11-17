#include "HumanB.hpp"

HumanB::HumanB(std::string _name)
:name(_name), WeaponB(0)
{
}

std::string const	&HumanB::getName()
{
	return(name);
}

void	HumanB::setWeapon(Weapon &_WeaponB)
{
	WeaponB = &_WeaponB;
}

void	HumanB::attack()
{
	std::cout << getName() << " attacks with their " << WeaponB->getType() << std::endl;
}
