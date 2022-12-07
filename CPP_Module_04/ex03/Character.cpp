#include "Character.hpp"

Character::Character()
	:name(""), Materia()
{
}

Character::Character(std::string name)
	:name(name), Materia()
{
}

Character::Character(Character& copy)
	:Materia()
{
	*this = copy;
}

Character& Character::operator=(Character& copy)
{
	if (this != &copy)
	{
		name = copy.getName();
		for (int i = 0; i < 4; i++)
			Materia[i] = copy.Materia[i];
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		delete Materia[i];
	}
}

std::string const&	Character::getName() const
{
	return (name);
}

void	Character::equip(AMateria* m)
{
	int	index = 0;

	while (Materia[index])
		index++;
	if (index > 3)
	{
		std::cerr << "Can't equip anymore!" << std::endl;
		return ;
	}
	Materia[index] = m;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cerr << "Parameter index is wrong!" << std::endl;
		return ;
	}
	Materia[idx] = 0;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
	{
		std::cerr << "Parameter index is wrong!" << std::endl;
		return ;
	}
	Materia[idx]->use(target);
}

