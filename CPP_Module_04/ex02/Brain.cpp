#include "Brain.hpp"

Brain::Brain()
	:index(0)
{
	std::cout << "Brain is born!" << std::endl;
}

Brain::Brain(Brain& copy)
	:index(0)
{
	*this = copy;
	std::cout << "Brain is cloned!" << std::endl;
}

Brain& Brain::operator=(Brain& copy)
{
	if (this != &copy)
	{
		index = 0;
		for (int i = 0; i < 100; i++)
			setIdea(copy.getIdea(i));
		index = copy.index;
	}
	return(*this);
}

Brain::~Brain()
{
	std::cout << "Brain is dead" << std::endl;
}

void	Brain::showIdea() const
{
	for (int i = 0; i < 100; i++)
	{
		if (!ideas[i].empty())
		{
			std::cout << i << ": \"" << ideas[i] << "\"" << std::endl;
		}
	}
}

std::string	const& Brain::getIdea(int i) const
{
	if (i < 0 || i > 99)
	{
		std::cerr << "Wrong index!" << std::endl;
		exit(1);
	}
	return(ideas[i]);
}

void	Brain::setIdea(std::string idea)
{
	ideas[index] = idea;
	index++;
	if (index == 100)
		index = 0;
}
