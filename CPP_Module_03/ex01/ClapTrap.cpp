#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	:_name(""), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
	std::cout << "Default ClapTrap created!" << std::endl;
}

ClapTrap::ClapTrap(const std::string name)
	:_name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << getName() << " created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	*this = copy;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& copy)
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

ClapTrap::~ClapTrap()
{
	if (getName() == "")
		std::cout << "Default ClapTrap destroyed!" << std::endl;
	else
		std::cout << "ClapTrap " << getName() << " destroyed!" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
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
	std::cout << "ClapTrap " << getName() << " attacks " << target << ", causing "
		<< getAttackDamage() << " points of damage!" << std::endl;
	setEnergyPoint(getEnergyPoint() - 1);
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > getHitPoint())
	{
		setHitPoint(0);
		return ;
	}
	setHitPoint(getHitPoint() - amount);
}

void	ClapTrap::beRepaired(unsigned int amount)
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
	setHitPoint(getHitPoint() + amount);
	setEnergyPoint(getEnergyPoint() - 1);
}


std::string	ClapTrap::getName() const
{
	return (_name);
}

unsigned int	ClapTrap::getHitPoint() const
{
	return (_hitPoint);
}

unsigned int	ClapTrap::getEnergyPoint() const
{
	return (_energyPoint);
}

unsigned int	ClapTrap::getAttackDamage() const
{
	return (_attackDamage);
}

void	ClapTrap::setName(const std::string name)
{
	_name = name;
}

void	ClapTrap::setHitPoint(const unsigned int hitPoint)
{
	_hitPoint = hitPoint;
}

void	ClapTrap::setEnergyPoint(const unsigned int energyPoint)
{
	_energyPoint = energyPoint;
}

void	ClapTrap::setAttackDamage(const unsigned int attackDamage)
{
	_attackDamage = attackDamage;
}
