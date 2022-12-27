#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class Intern {
	public:
		Intern();
		Intern(Intern& copy);

		Intern&	operator=(Intern& copy);

		virtual ~Intern();

		AForm*	makeForm(std::string name, std::string target);

		class nameException : public std::exception {
			public:
				const char* what() const throw();
		};
};

#endif
