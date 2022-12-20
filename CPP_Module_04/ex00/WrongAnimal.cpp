#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
	:type("WrongAnimal")
{
	std::cout << getType() << " is born!" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal& copy)
{
	*this = copy;
	std::cout << getType() << " is cloned!" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal& copy)
{
	if (this != &copy)
	{
		setType(copy.getType());
	}
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << getType() << " is dead!" << std::endl;
}

void	WrongAnimal::setType(std::string _type)
{
	type = _type;
}

std::string	WrongAnimal::getType() const
{
	return (type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "?!?!?!?" << std::endl;
}
