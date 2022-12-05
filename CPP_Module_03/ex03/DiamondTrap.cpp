#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	: ClapTrap(), ScavTrap(), FragTrap(), name("unknown")
{
	ClapTrap::setName(ClapTrap::getName() + "_clap_name");
	setHitPoint(100);
	setEnergyPoint(50);
	setAttackDamage(30);
	std::cout << "Default DiamondTrap created!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name), ScavTrap(name), FragTrap(name), name(name)
{
	ClapTrap::setName(ClapTrap::getName() + "_clap_name");
	setHitPoint(100);
	setEnergyPoint(50);
	setAttackDamage(30);
	std::cout << "DiamondTrap " << getName() << " created!" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap& copy)
	: ClapTrap(), ScavTrap(), FragTrap()
{
	*this = copy;
	std::cout << "DiamondTrap " << getName() << " be reproduced!" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap& copy)
{
	if (this != &copy)
	{
		setName(copy.getName());
		ClapTrap::operator=(copy);
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << getName() << " destroyed!" << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::takeDamage(unsigned int amount)
{
	FragTrap::takeDamage(amount);
}

void	DiamondTrap::beRepaired(unsigned int amount)
{
	ScavTrap::beRepaired(amount);
}

void	DiamondTrap::whoAmI()
{
	if (getHitPoint() == 0)
	{
		std::cout << "DiamondTrap " << getName() << " is died" << std::endl;
		return ;
	}
	if (getEnergyPoint() == 0)
	{
		std::cout << "DiamondTrap " << getName() << " doesn't have enough Energy Point" << std::endl;
		return ;
	}
	std::cout << "My name is " << getName() << " and my ClapTrap name is " << ClapTrap::getName() << std::endl;
}

std::string DiamondTrap::getName() const
{
	return (name);
}

void	DiamondTrap::setName(std::string name)
{
	this->name = name;
}
