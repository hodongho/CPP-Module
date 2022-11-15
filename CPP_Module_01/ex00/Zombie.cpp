#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Zombie is born" << std::endl;
}

Zombie::Zombie( std::string _name )
{
	name = _name;
	std::cout << "The " << name << " is born" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "The " << name << " is dead" << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}
