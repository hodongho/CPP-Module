#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::string dog = "My type is Dog";
		std::string cat = "My type is Cat";

		delete j;
		delete i;
	}
	{
		Animal* Animals[4];
		for (int i = 0; i < 3; i++)
		{
			if (i < 1)
				Animals[i] = new Dog();
			else
				Animals[i] = new Cat();
		}
	}
	return (0);
}
