#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	// {
	// 	try
	// 	{
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cout << e.what() << std::endl;
	// 	}
	// }

	// std::cout << std::endl << "----------------------------------------------" << std::endl << std::endl;

	// {
	// 	try
	// 	{
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cout << e.what() << std::endl;
	// 	}
	// }

	// std::cout << std::endl << "----------------------------------------------" << std::endl << std::endl;

	{
		Bureaucrat	A("A", 1);

		ShrubberyCreationForm	Home("home");

		std::cout << A << std::endl;
		try
		{
			A.signForm(Home);
			// A.signForm();
			// A.signForm();
			// A.signForm();
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	// std::cout << std::endl << "----------------------------------------------" << std::endl << std::endl;

	// {
	// 	Bureaucrat B("B", 75);

	// 	std::cout << B << std::endl;
	// 	try
	// 	{
	// 		B.signForm();
	// 		B.signForm();
	// 		B.signForm();
	// 		B.signForm();
	// 	}
	// 	catch (std::exception& e)
	// 	{
	// 		std::cout << e.what() << std::endl;
	// 	}
	// }

	// std::cout << std::endl << "----------------------------------------------" << std::endl << std::endl;

	// {
	// 	Bureaucrat C("C", 150);

	// 	std::cout << C << std::endl;
	// 	try
	// 	{
	// 		C.signForm();
	// 		C.signForm();
	// 		C.signForm();
	// 		C.signForm();
	// 	}
	// 	catch (std::exception& e)
	// 	{
	// 		std::cout << e.what() << std::endl;
	// 	}
	// }
	return (0);
}
