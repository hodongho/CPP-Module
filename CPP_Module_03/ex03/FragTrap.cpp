#include "FragTrap.hpp"

FragTrap::FragTrap()
	:ClapTrap()
{
	setHitPoint(100);
	setEnergyPoint(100);
	setAttackDamage(30);
	std::cout << "FragTrap " << getName() << " created!" << std::endl;
}

FragTrap::FragTrap(std::string name)
	:ClapTrap(name)
{
	setHitPoint(100);
	setEnergyPoint(100);
	setAttackDamage(30);
	std::cout << "FragTrap " << getName() << " created!" << std::endl;
}

FragTrap::FragTrap(FragTrap& copy)
	:ClapTrap()
{
	*this = copy;
	std::cout << "FragTrap " << getName() << " be reproduced!" << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap& copy)
{
	if (this != &copy)
		ClapTrap::operator=(copy);
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << getName() << " destroyed!" << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (getHitPoint() == 0)
	{
		std::cout << "FragTrap " << getName() << " is died" << std::endl;
		return ;
	}
	if (getEnergyPoint() == 0)
	{
		std::cout << "FragTrap " << getName() << " doesn't have enough Energy Point" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << getName() << " attacks " << target << ", causing "
		<< getAttackDamage() << " points of damage!" << std::endl;
	setEnergyPoint(getEnergyPoint() - 1);
}

void	FragTrap::takeDamage(unsigned int amount)
{

	if (getHitPoint() == 0)
	{
		std::cout << "FragTrap " << getName() << " is died" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << getName() << " takes " << amount << " points of damage!" << std::endl;
	if (amount > getHitPoint())
	{
		setHitPoint(0);
		return ;
	}
	setHitPoint(getHitPoint() - amount);
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (getHitPoint() == 0)
	{
		std::cout << "FragTrap " << getName() << " is died" << std::endl;
		return ;
	}
	if (getEnergyPoint() == 0)
	{
		std::cout << "FragTrap " << getName() << " doesn't have enough Energy Point" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << getName() << " repaired " << amount << " points" << std::endl;
	setHitPoint(getHitPoint() + amount);
	setEnergyPoint(getEnergyPoint() - 1);
}

void	FragTrap::highFivesGuys()
{
	if (getHitPoint() == 0)
	{
		std::cout << "FragTrap " << getName() << " is died" << std::endl;
		return ;
	}
	if (getEnergyPoint() == 0)
	{
		std::cout << "FragTrap " << getName() << " doesn't have enough Energy Point" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << getName() << " request positive high fives!" << std::endl;
}
