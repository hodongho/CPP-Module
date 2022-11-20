#include "Zombie.hpp"

int	main()
{
	Zombie	*Horde;

	Horde = zombieHorde(0, "Foo");
	for(int i = 0; i < 1; i++)
		Horde[i].announce();
	delete [] Horde;
	return (0);
}
