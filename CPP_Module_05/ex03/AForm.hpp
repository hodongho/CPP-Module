#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string	name;
		bool				sign;
		const int			signRequest;
		const int			execRequest;

	public:
		AForm();
		AForm(std::string name, int signRequest, int execRequest);
		AForm(AForm& copy);

		AForm& operator=(AForm& copy);

		virtual ~AForm();

		const std::string&	getName() const;
		bool				getSign() const;
		const int&			getSignRequest() const;
		const int&			getExecRequest() const;

		void				beSigned(Bureaucrat& b);
		virtual void		execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::exception {
			const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			const char* what() const throw();
		};

		class SignException : public std::exception {
			const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& out, const AForm& AForm);

#endif
