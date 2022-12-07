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

		std::cout << std::endl;

		delete j;
		delete i;
	}
	std::cout << "-----------------------------------------" << std::endl;
	{
		Animal* Animals[4];
		std::string dog = "My type is Dog";
		std::string cat = "My type is Cat";

		std::cout << std::endl;

		for (int i = 0; i < 4; i++)
		{
			if (i % 2)
			{
				Animals[i] = new Dog();
				((Dog *)Animals[i])->setIdea(dog);
			}
			else
			{
				Animals[i] = new Cat();
				((Cat *)Animals[i])->setIdea(cat);
			}
			std::cout << std::endl;
		}

		std::cout << std::endl;

		for (int i = 0; i < 4; i++)
		{
			std::cout << "[ Animal " << i << ": " << Animals[i]->getType() << " ] " << std::endl;
			if (Animals[i]->getType() == "Dog")
			{
				((Dog *)Animals[i])->showIdea();
			}
			else
			{
				((Cat *)Animals[i])->showIdea();
			}
			std::cout << std::endl;
		}

		std::cout << std::endl;

		for (int i = 0; i < 4; i++)
			delete Animals[i];
	}
	std::cout << "-----------------------------------------" << std::endl;
	{
		Dog	*D1 = new Dog;
		std::string dog = "My type is Dog";

		std::cout << std::endl;

		D1->setIdea(dog);
		D1->showIdea();

		std::cout << std::endl;

		Dog	D2(*D1);
		std::cout << std::endl;
		delete D1;

		std::cout << std::endl;

		D2.showIdea();

		std::cout << std::endl;
	}
	// {
	// 	Animal animal;
	// }
	return (0);
}
