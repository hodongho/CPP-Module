#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal {
	private:
		Brain *dogBrain;
	public:
		Dog();
		Dog(Dog& copy);

		Dog& operator=(Dog& copy);

		~Dog();

		void				makeSound() const;
		void 				showIdea() const;
		std::string const&	getIdea(int	i) const;
		void				setIdea(std::string idea);
};

#endif
