#include "HumanB.hpp"

HumanB::HumanB(std::string _name)
:name(_name), WeaponB(0)
{
}

const std::string	&HumanB::getName()
{
	return(name);
}

void	HumanB::setWeapon(Weapon &_WeaponB)
{
	WeaponB = &_WeaponB;
}

void	HumanB::attack()
{
	if (WeaponB == 0)
	{
		std::cout << getName() << " doesn't have Weapon!" << std::endl;
		return ;
	}
	std::cout << getName() << " attacks with their " << WeaponB->getType() << std::endl;
}
