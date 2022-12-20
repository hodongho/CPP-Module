#include "AMateria.hpp"

AMateria::AMateria()
	:type("")
{
}

AMateria::AMateria(AMateria& copy)
	:type(copy.getType())
{
}

AMateria::AMateria(std::string const& type)
	:type(type)
{
}

AMateria& AMateria::operator=(AMateria& copy)
{
	(void)copy;
	return (*this);
}

AMateria::~AMateria()
{
}

std::string const& AMateria::getType() const
{
	return (type);
}

void	AMateria::use(ICharacter& target)
{
		std::cout << "* " << target.getName() << " *" << std::endl;
}
