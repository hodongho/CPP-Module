#include "AAnimal.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	{
		const AAnimal* j = new Dog();
		const AAnimal* i = new Cat();

		std::cout << std::endl;

		delete j;
		delete i;

		std::cout << std::endl;
		system("leaks -quiet a.out");
	}
	std::cout << "-----------------------------------------" << std::endl;
	{
		AAnimal* AAnimals[4];
		std::string dog = "My type is Dog";
		std::string cat = "My type is Cat";

		std::cout << std::endl;

		for (int i = 0; i < 4; i++)
		{
			if (i % 2)
			{
				AAnimals[i] = new Dog();
				((Dog *)AAnimals[i])->setIdea(dog);
			}
			else
			{
				AAnimals[i] = new Cat();
				((Cat *)AAnimals[i])->setIdea(cat);
			}
			std::cout << std::endl;
		}

		std::cout << std::endl;

		for (int i = 0; i < 4; i++)
		{
			std::cout << "[ AAnimal " << i << ": " << AAnimals[i]->getType() << " ] " << std::endl;
			if (AAnimals[i]->getType() == "Dog")
			{
				((Dog *)AAnimals[i])->showIdea();
			}
			else
			{
				((Cat *)AAnimals[i])->showIdea();
			}
			std::cout << std::endl;
		}

		std::cout << std::endl;

		for (int i = 0; i < 4; i++)
			delete AAnimals[i];

		std::cout << std::endl;
		system("leaks -quiet a.out");
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
		system("leaks -quiet a.out");
	}
	return (0);
}
