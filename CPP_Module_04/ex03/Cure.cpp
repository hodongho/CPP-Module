#include "Cure.hpp"

Cure::Cure()
{
	type = "cure";
}

Cure::Cure(Cure& copy)
{
	*this = copy;
}

Cure&	Cure::operator=(Cure& copy)
{
	(void)copy;
	return (*this);
}

Cure::~Cure()
{
}

AMateria*	Cure::clone() const
{
	AMateria* cloneCure = new Cure;
	return (cloneCure);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
