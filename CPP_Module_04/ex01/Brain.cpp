#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain is create!" << std::endl;
}

Brain::Brain(Brain& copy)
{
	std::cout << "Brain is cloned!" << std::endl;
}

Brain& Brain::operator=(Brain& copy)
{
}

Brain::~Brain()
{
}
