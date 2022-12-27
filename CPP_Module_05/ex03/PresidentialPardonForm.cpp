#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	:AForm("PresidentialPardonForm", P_SIGN, P_EXEC), target("")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	:AForm("PresidentialPardonForm", P_SIGN, P_EXEC), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& copy)
	:AForm(copy.getName(), P_SIGN, P_EXEC), target(copy.getTarget())
{
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm&)
{
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

const std::string& PresidentialPardonForm::getTarget() const
{
	return (target);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (getSign() == false)
		throw (notSignException());
	if (executor.getGrade() > getExecRequest())
		throw (GradeTooLowException());
	std::cout << getTarget() << "has been pardoned by Zaphod Beeblebrox" << std::endl;
}
