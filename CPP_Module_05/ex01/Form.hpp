#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string	name;
		bool				sign;
		const int			signRequest;
		const int			execRequest;

	public:
		Form();
		Form(std::string name, int signRequest, int execRequest);
		Form(Form& copy);

		Form& operator=(Form& copy);

		virtual ~Form();

		const std::string&	getName() const;
		bool				getSign() const;
		const int&			getSignRequest() const;
		const int&			getExecRequest() const;

		void				beSigned(Bureaucrat& b);

		class GradeTooHighException : public std::exception {
			const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			const char* what() const throw();
		};

		class RequestTooHighException : public std::exception {
			const char* what() const throw();
		};

		class RequestTooLowException : public std::exception {
			const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& out, const Form& Form);

#endif
