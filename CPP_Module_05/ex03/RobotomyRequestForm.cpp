#include "RobotomyRequestForm.hpp"
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
	:AForm("RobotomyRequestForm", R_SIGN, R_EXEC), target("")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	:AForm("RobotomyRequestForm", R_SIGN, R_EXEC), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& copy)
	:AForm(copy.getName(), R_SIGN, R_EXEC), target(copy.getTarget())
{
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm&)
{
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

const std::string& RobotomyRequestForm::getTarget() const
{
	return (target);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (getSign() == false)
		throw (notSignException());
	if (executor.getGrade() > getExecRequest())
		throw (GradeTooLowException());

	time_t	t;

	t = time(NULL);
	if (t / 2)
		std::cout << "wing~ wing~" << std::endl;
	else
		std::cout << "..." << std::endl;
}
