#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern	someRandomIntern;
	AForm*	FormCase[5];

	try
	{
		FormCase[0] = someRandomIntern.makeForm("shrubbery creations", "A");
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		FormCase[0] = someRandomIntern.makeForm("shrubbery creation123", "A");
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		FormCase[0] = someRandomIntern.makeForm("123shrubbery creation", "A");
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		FormCase[0] = someRandomIntern.makeForm("shrubbery123 creation", "A");
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		FormCase[0] = someRandomIntern.makeForm("123robotomy request", "A");
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	FormCase[0] = someRandomIntern.makeForm("shrubbery creation", "A");
	FormCase[1] = someRandomIntern.makeForm("shrubbery creation", "B");
	FormCase[2] = someRandomIntern.makeForm("shrubbery creation", "C");
	FormCase[3] = someRandomIntern.makeForm("robotomy request", "R");
	FormCase[4] = someRandomIntern.makeForm("presidential pardon", "P");

	std::cout << std::endl;

	Bureaucrat	M("M", 1);

	std::cout << M << std::endl;

	M.executeForm(*FormCase[0]);
	M.executeForm(*FormCase[3]);
	M.executeForm(*FormCase[4]);

	std::cout << std::endl;

	M.signForm(*FormCase[0]);
	M.signForm(*FormCase[1]);
	M.signForm(*FormCase[2]);
	M.signForm(*FormCase[3]);
	M.signForm(*FormCase[4]);

	std::cout << std::endl << "----------------------------------------------" << std::endl << std::endl;

	{
		Bureaucrat	A("A", 1);

		std::cout << A << std::endl;
		try
		{
			A.executeForm(*FormCase[0]);
			A.executeForm(*FormCase[3]);
			A.executeForm(*FormCase[4]);
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl << "----------------------------------------------" << std::endl << std::endl;

	{
		Bureaucrat B("B", 75);

		std::cout << B << std::endl;
		try
		{
			B.executeForm(*FormCase[1]);
			B.executeForm(*FormCase[3]);
			B.executeForm(*FormCase[4]);
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl << "----------------------------------------------" << std::endl << std::endl;

	{
		Bureaucrat C("C", 150);

		std::cout << C << std::endl;
		try
		{
			C.executeForm(*FormCase[2]);
			C.executeForm(*FormCase[3]);
			C.executeForm(*FormCase[4]);
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	for (int i = 0; i < 5; i++)
		delete FormCase[i];
	return (0);
}
