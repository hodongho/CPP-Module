#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
	:ClapTrap()
{
	setHitPoint(100);
	setEnergyPoint(50);
	setAttackDamage(20);
	std::cout << "ScavTrap " << getName() << " created!" << std::endl;
}

ScavTrap::ScavTrap(const std::string name)
	:ClapTrap(name)
{
	setHitPoint(100);
	setEnergyPoint(50);
	setAttackDamage(20);
	std::cout << "ScavTrap " << getName() << " created!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy)
	:ClapTrap()
{
	*this = copy;
	std::cout << "ScavTrap " << getName() << " be reproduced!" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& copy)
{
	if (this != &copy)
		ClapTrap::operator=(copy);
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << getName() << " destroyed!" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (getHitPoint() == 0)
	{
		std::cout << "ScavTrap "<< getName() << " is died" << std::endl;
		return ;
	}
	if (getEnergyPoint() == 0)
	{
		std::cout << "ScavTrap "<< getName() << " doesn't have enough Energy Point" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing "
		<< getAttackDamage() << " points of damage!" << std::endl;
	setEnergyPoint(getEnergyPoint() - 1);
}

void	ScavTrap::takeDamage(unsigned int amount)
{

	if (getHitPoint() == 0)
	{
		std::cout << "ScavTrap "<< getName() << " is died" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << getName() << " takes " << amount << " points of damage!" << std::endl;
	if (amount > getHitPoint())
	{
		setHitPoint(0);
		return ;
	}
	setHitPoint(getHitPoint() - amount);
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (getHitPoint() == 0)
	{
		std::cout << "ScavTrap "<< getName() << " is died" << std::endl;
		return ;
	}
	if (getEnergyPoint() == 0)
	{
		std::cout << "ScavTrap "<< getName() << " doesn't have enough Energy Point" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << getName() << " repaired " << amount << " points" << std::endl;
	setHitPoint(getHitPoint() + amount);
	setEnergyPoint(getEnergyPoint() - 1);
}

void	ScavTrap::guardGate()
{
	if (getHitPoint() == 0)
	{
		std::cout << "ScavTrap "<< getName() << " is died" << std::endl;
		return ;
	}
	if (getEnergyPoint() == 0)
	{
		std::cout << "ScavTrap "<< getName() << " doesn't have enough Energy Point" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << getName() << " is now in Gatekeeper mode" << std::endl;
}
