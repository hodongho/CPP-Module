#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	:AForm("ShrubberyCreationForm", S_SIGN, S_EXEC), target("")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	:AForm("ShrubberyCreationForm", S_SIGN, S_EXEC), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& copy)
	:AForm(copy.getName(), S_SIGN, S_EXEC), target(copy.getTarget())
{
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm&)
{
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

const std::string& ShrubberyCreationForm::getTarget() const
{
	return (target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (getSign() == false)
		throw (notSignException());
	if (executor.getGrade() > getExecRequest())
		throw (GradeTooLowException());

	std::string filename = getTarget();

	filename.append("_shrubbery");

	std::ofstream	file(filename.c_str());

	file	<< "       *" << std::endl
			<< "     _/ \\_" << std::endl
			<< "    \\     /" << std::endl
			<< "    /_' '_\\" << std::endl
			<< "     /'+ \\" << std::endl
			<< "    / o o \\" << std::endl
			<< "   /  -' *-\\" << std::endl
			<< "  /.  oo+...\\" << std::endl
			<< " /o- @ o @o' \\" << std::endl
			<< "*-------------*" << std::endl
			<< "   [_______]" << std::endl
			<< "    \\_____/" << std::endl;
}
