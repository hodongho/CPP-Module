#include "Dog.hpp"

Dog::Dog()
{
	setType("Dog");
	std::cout << getType() << " is born!" << std::endl;
}

Dog::Dog(Dog& copy)
{
	*this = copy;
	std::cout << getType() << " is cloned!" << std::endl;
}

Dog& Dog::operator=(Dog& copy)
{
	if (this != &copy)
		setType(copy.getType());
	return (*this);
}

Dog::~Dog()
{
	std::cout << getType() << " is dead!" << std::endl;
}

void	Dog::makeSound()const
{
	std::cout << "Woof" << std::endl;
}

