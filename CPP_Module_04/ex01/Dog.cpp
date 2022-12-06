#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	dogBrain = new Brain();
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
	{
		type = copy.getType();
		for (int i = 0; i < 99; i++)
			setIdea(copy.getIdea(i), i);
	}
	return (*this);
}

Dog::~Dog()
{
	delete dogBrain;
	std::cout << getType() << " is dead!" << std::endl;
}

void	Dog::makeSound()const
{
	std::cout << "Woof" << std::endl;
}

std::string const&	Dog::getIdea(int i) const
{
	return(dogBrain->getIdea(i));
}

void	Dog::setIdea(std::string idea, int i)
{
	dogBrain->setIdea(idea, i);
}
