#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal {
	protected:
		std::string type;

		void	setType(std::string _type);
	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal& copy);

		WrongAnimal& operator=(WrongAnimal& copy);

		~WrongAnimal();

		std::string 	getType() const;
		void			makeSound() const;
};

#endif
