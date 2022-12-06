#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {
	protected:
		std::string type;

	public:
		Animal();
		Animal(Animal& copy);

		Animal& operator=(Animal& copy);

		virtual	~Animal();

		std::string const&	getType() const;
		virtual void		makeSound() const;
};

#endif
