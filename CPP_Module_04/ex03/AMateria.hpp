#ifndef AMATERIA_HPP
# define AMATERIA_HPP

class	AMateria;

# include <iostream>
# include "ICharacter.hpp"

class AMateria {
	protected:
		std::string	type;
	public:
		AMateria();
		AMateria(AMateria& copy);
		AMateria(std::string const& type);

		AMateria& operator=(AMateria& copy);

		virtual ~AMateria();

		std::string const& getType() const;

		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);
};

#endif
