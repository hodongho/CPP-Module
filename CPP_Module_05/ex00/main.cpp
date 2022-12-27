#include "Bureaucrat.hpp"

int main()
{
	std::cout << std::endl << "--------------------Start!--------------------" << std::endl << std::endl;

	{
		try
		{
			Bureaucrat H("H", 0);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << std::endl << "----------------------------------------------" << std::endl << std::endl;

	{
		try
		{
			Bureaucrat L("L", 151);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << std::endl << "----------------------------------------------" << std::endl << std::endl;

	{
		Bureaucrat A("A", 1);

		std::cout << A << std::endl;
		try
		{
			A.increaseGrade();
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		A.decreaseGrade();
		std::cout << A << std::endl;
	}

	std::cout << std::endl << "----------------------------------------------" << std::endl << std::endl;

	{
		Bureaucrat B("B", 150);

		std::cout << B << std::endl;
		try
		{
			B.decreaseGrade();
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		B.increaseGrade();
		std::cout << B << std::endl;
	}
	return (0);
}
