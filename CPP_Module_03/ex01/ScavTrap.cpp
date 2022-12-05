#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	setName("");
	setHitPoint(100);
	setEnergyPoint(50);
	setAttackDamage(20);
	std::cout << "Default ScavTrap created!" << std::endl;
}

ScavTrap::ScavTrap(const std::string name)
{
	setName(name);
	setHitPoint(100);
	setEnergyPoint(50);
	setAttackDamage(20);
	std::cout << "ScavTrap " << getName() << " created!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy)
{
	*this = copy;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& copy)
{
	if (this != &copy)
	{
		setName(copy.getName());
		setHitPoint(copy.getHitPoint());
		setEnergyPoint(copy.getEnergyPoint());
		setAttackDamage(copy.getAttackDamage());
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	if (getName() == "")
		std::cout << "Default ScavTrap destroyed!" << std::endl;
	else
		std::cout << "ScavTrap " << getName() << " destroyed!" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (getHitPoint() == 0)
	{
		std::cout << getName() << " doesn't have enough hit Point" << std::endl;
		return ;
	}
	if (getEnergyPoint() == 0)
	{
		std::cout << getName() << " doesn't have enough Energy Point" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing "
		<< getAttackDamage() << " points of damage!" << std::endl;
	setEnergyPoint(getEnergyPoint() - 1);
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << getName() << " is now in Gatekeeper mode" << std::endl;
}
