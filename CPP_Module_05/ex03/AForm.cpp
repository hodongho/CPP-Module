#include "AForm.hpp"

AForm::AForm()
	:name(""), sign(false), signRequest(150), execRequest(150)
{
}

AForm::AForm(std::string name, int signRequest, int execRequest)
	:name(name), sign(false), signRequest(signRequest), execRequest(execRequest)
{
	if (signRequest < HIGHEST_G || execRequest < HIGHEST_G)
		throw(Bureaucrat::GradeTooHighException());
	else if (signRequest > LOWEST_G || execRequest > LOWEST_G)
		throw(Bureaucrat::GradeTooLowException());
}

AForm::AForm(AForm& copy)
	:	name(copy.getName()),
		sign(copy.getSign()),
		signRequest(copy.getSignRequest()),
		execRequest(copy.getExecRequest())
{
}

AForm& AForm::operator=(AForm& copy)
{
	if (this != &copy)
	{
		sign = copy.getSign();
	}
	return (*this);
}

AForm::~AForm()
{
}

const std::string&	AForm::getName() const
{
	return (name);
}

bool	AForm::getSign() const
{
	return (sign);
}

const int&	AForm::getSignRequest() const
{
	return (signRequest);
}

const int&	AForm::getExecRequest() const
{
	return (execRequest);
}

void	AForm::beSigned(Bureaucrat& b)
{
	if (b.getGrade() > getSignRequest())
		throw (GradeTooLowException());
	if (sign == true)
		std::cout << "This AForm is already signed" << std::endl;
	else
		sign = true;
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("Your grade too high");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("Your grade too low");
}

const char*	AForm::SignException::what() const throw()
{
	return("This form is already signed");
}

const char*	AForm::notSignException::what() const throw()
{
	return("This form is not signed");
}

std::ostream&	operator<<(std::ostream& out, const AForm& AForm)
{
	out << AForm.getName()
		<< "'s informations" << std::endl
		<< " Sign : " << AForm.getSign()
		<< " Sign Request : " << AForm.getSignRequest()
		<< " Execute Request : " << AForm.getExecRequest() << std::endl;
	return (out);
}
