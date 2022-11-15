#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Zombie is born" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "The " << name << " is dead" << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::SetName( std::string _name)
{
	name = _name;
}
