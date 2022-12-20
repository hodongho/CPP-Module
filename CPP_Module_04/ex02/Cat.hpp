#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal {
	private:
		Brain *catBrain;
	public:
		Cat();
		Cat(Cat& copy);

		Cat& operator=(Cat& copy);

		~Cat();

		void				makeSound() const;
		void				showIdea() const;
		std::string const&	getIdea(int	i) const;
		void				setIdea(std::string idea);
};

#endif
