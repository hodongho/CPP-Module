#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern& copy)
{
	*this = copy;
}

Intern&	Intern::operator=(Intern& copy)
{
	(void)copy;
	return (*this);
}

Intern::~Intern()
{
}

AForm*	Intern::makeForm(std::string name, std::string target)
{
	std::string	str("<shrubbery creation><robotomy request><presidential pardon>");
	std::string FormName("");
	AForm*		ret;

	name.insert(0, "<");
	name += ">";
	switch (str.find(name))
	{
		case 0:
		{
			ret = new ShrubberyCreationForm(target);
			FormName = "ShrubberyCreationForm";
			break ;
		}
		case 20:
		{
			ret = new RobotomyRequestForm(target);
			FormName = "RobotomyRequestForm";
			break ;
		}
		case 38:
		{
			ret = new PresidentialPardonForm(target);
			FormName = "PresidentialPardonForm";
			break ;
		}
		default:
			throw (nameException());
	}
	std::cout << "Intern creates " << FormName << std::endl;
	return (ret);
}

const char* Intern::nameException::what() const throw()
{
	return("Can't create form!");
}
