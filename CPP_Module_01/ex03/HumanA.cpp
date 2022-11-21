#include "HumanA.hpp"

HumanA::HumanA(std::string _name, Weapon &_WeaponA)
:name(_name), WeaponA(_WeaponA)
{
}

const std::string	&HumanA::getName()
{
	return(name);
}

void	HumanA::setWeapon(Weapon _WeaponA)
{
	WeaponA = _WeaponA;
}

void	HumanA::attack()
{
	std::cout << getName() << " attacks with their " << WeaponA.getType() << std::endl;
}
