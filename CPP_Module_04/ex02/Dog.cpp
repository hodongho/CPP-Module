#include "Dog.hpp"

Dog::Dog()
	:dogBrain(0)
{
	type = "Dog";
	std::cout << getType() << " is born!" << std::endl;
	dogBrain = new Brain();
}

Dog::Dog(Dog& copy)
	:dogBrain(0)
{
	*this = copy;
	std::cout << getType() << " is cloned!" << std::endl;
}

Dog& Dog::operator=(Dog& copy)
{
	if (this != &copy)
	{
		type = copy.getType();
		if (dogBrain != 0)
			delete dogBrain;
		dogBrain = new Brain(*copy.dogBrain);
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

void	Dog::showIdea() const
{
	dogBrain->showIdea();
}

std::string const&	Dog::getIdea(int i) const
{
	return(dogBrain->getIdea(i));
}

void	Dog::setIdea(std::string idea)
{
	dogBrain->setIdea(idea);
}
