#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "AForm.hpp"

# define HIGHEST_G 1
# define LOWEST_G 150

class AForm;

class Bureaucrat {
	private:
		const std::string	name;
		int					grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat& copy);

		Bureaucrat& operator=(Bureaucrat& copy);

		virtual ~Bureaucrat();

		const std::string&	getName() const;
		const int&			getGrade() const;
		void				increaseGrade();
		void				decreaseGrade();
		void				signForm(AForm& form);
		void				executeForm(AForm const & form);

		class GradeTooHighException : public std::exception {
			public:
				const char*	what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char*	what() const throw();
		};
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat& Bureaucrat);

#endif
