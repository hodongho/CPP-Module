#include "Animal.hpp"

Animal::Animal()
	:type("Animal")
{
	std::cout << getType() << " is born!" << std::endl;
}

Animal::Animal(Animal& copy)
{
	*this = copy;
	std::cout << getType() << " is cloned!" << std::endl;
}

Animal& Animal::operator=(Animal& copy)
{
	if (this != &copy)
	{
		setType(copy.getType());
	}
	return (*this);
}

Animal::~Animal()
{
	std::cout << getType() << " is dead!" << std::endl;
}

void	Animal::setType(std::string _type)
{
	type = _type;
}

std::string	Animal::getType() const
{
	return (type);
}

void	Animal::makeSound() const
{
	std::cout << "???" << std::endl;
}
