#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {
	protected:
		std::string type;

		void	setType(std::string _type);
	public:
		Animal();
		Animal(Animal& copy);

		Animal& operator=(Animal& copy);

		~Animal();

		std::string 	getType() const;
		virtual void	makeSound() const;
};

#endif
