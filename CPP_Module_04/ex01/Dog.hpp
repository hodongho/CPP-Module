#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain *dogBrain;
	public:
		Dog();
		Dog(Dog& copy);

		Dog& operator=(Dog& copy);

		~Dog();

		void		makeSound() const;
		std::string const&	getIdea(int	i) const;
		void				setIdea(std::string idea, int i);
};

#endif
