#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *zombieHorde = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		zombieHorde[i].SetName(name);
	}
	return (zombieHorde);
}
