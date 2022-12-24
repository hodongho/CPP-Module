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
	if (getSign() != true)
		return ;
	if (executor.getGrade() > getExecRequest())
		return ;

	time_t	time;

	if (time / 2)
		std::cout << "wing~ wing~" << std::endl;
	else
		std::cout << "..." << std::endl;
}
