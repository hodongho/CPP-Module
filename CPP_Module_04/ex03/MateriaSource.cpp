#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
	:Materia()
{
}

MateriaSource::MateriaSource(MateriaSource& copy)
	:Materia()
{
	*this = copy;
}

MateriaSource&	MateriaSource::operator=(MateriaSource& copy)
{
	if (this != &copy)
	{
		for (int i = 0; i < 4; i++)
			Materia[i] = copy.Materia[i];
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
}

void	MateriaSource::learnMateria(AMateria* m)
{
	int	index = 0;

	while (index < 4 && Materia[index])
		index++;
	if (index == 4)
	{
		std::cerr << "Can't learn anymore!" << std::endl;
		return ;
	}
	Materia[index] = m;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (Materia[i] && Materia[i]->getType() == type)
			return (Materia[i]);
	}
	std::cerr << "Wrong parameter type!" << std::endl;
	return (0);
}
