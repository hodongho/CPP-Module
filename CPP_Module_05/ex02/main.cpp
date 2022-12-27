#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	ShrubberyCreationForm	HomeA("A");
	ShrubberyCreationForm	HomeB("B");
	ShrubberyCreationForm	HomeC("C");

	RobotomyRequestForm		R("R");

	PresidentialPardonForm	P("P");

	Bureaucrat	M("M", 1);

	std::cout << M << std::endl;

	M.executeForm(HomeA);
	M.executeForm(R);
	M.executeForm(P);

	std::cout << std::endl;

	M.signForm(HomeA);
	M.signForm(HomeB);
	M.signForm(HomeC);
	M.signForm(R);
	M.signForm(P);

	std::cout << std::endl << "----------------------------------------------" << std::endl << std::endl;

	{
		Bureaucrat	A("A", 1);

		std::cout << A << std::endl;
		try
		{
			A.executeForm(HomeA);
			A.executeForm(R);
			A.executeForm(P);
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
			B.executeForm(HomeB);
			B.executeForm(R);
			B.executeForm(P);
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
			C.executeForm(HomeC);
			C.executeForm(R);
			C.executeForm(P);
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}
