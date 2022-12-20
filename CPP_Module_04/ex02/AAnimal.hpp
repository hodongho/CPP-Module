#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal {
	protected:
		std::string type;

	public:
		AAnimal();
		AAnimal(AAnimal& copy);

		AAnimal& operator=(AAnimal& copy);

		virtual	~AAnimal();

		std::string const&	getType() const;
		virtual void		makeSound() const = 0;
};

#endif
