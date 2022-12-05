#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		WrongCat();
		WrongCat(WrongCat& copy);

		WrongCat& operator=(WrongCat& copy);

		~WrongCat();

		void	makeSound() const;
};

#endif
