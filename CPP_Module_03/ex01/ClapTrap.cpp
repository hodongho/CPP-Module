#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	:name(""), hitPoint(10), energyPoint(10), attackDamage(0)
{
	std::cout << "Default ClapTrap created!" << std::endl;
}

ClapTrap::ClapTrap(const std::string _name)
	:name(_name), hitPoint(10), energyPoint(10), attackDamage(0)
{
	std::cout << "ClapTrap " << getName() << " created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	*this = copy;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& copy)
{
	if (this == &copy)
		return (*this);
	name = copy.getName();
	hitPoint = copy.getHitPoint();
	energyPoint = copy.getEnergyPoint();
	attackDamage = copy.getAttackDamage();
	return (*this);
}

ClapTrap::~ClapTrap()
{
	if (name == "")
		std::cout << "Default ClapTrap destroyed!" << std::endl;
	else
		std::cout << "ClapTrap " << getName() << " destroyed!" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (hitPoint == 0)
	{
		std::cout << getName() << " aren't enough hit Point" << std::endl;
		return ;
	}
	if (energyPoint == 0)
	{
		std::cout << getName() << " aren't enough Energy Point" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << getName() << " attacks " << target << ", causing "
		<< getAttackDamage() << " points of damage!" << std::endl;
	energyPoint--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > hitPoint)
	{
		hitPoint = 0;
		return ;
	}
	hitPoint -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoint == 0)
	{
		std::cout << getName() << " aren't enough hit Point" << std::endl;
		return ;
	}
	if (energyPoint == 0)
	{
		std::cout << getName() << " aren't enough Energy Point" << std::endl;
		return ;
	}
	hitPoint += amount;
	energyPoint--;
}


std::string	ClapTrap::getName() const
{
	return (name);
}

unsigned int	ClapTrap::getHitPoint() const
{
	return (hitPoint);
}

unsigned int	ClapTrap::getEnergyPoint() const
{
	return (energyPoint);
}

unsigned int	ClapTrap::getAttackDamage() const
{
	return (attackDamage);
}
