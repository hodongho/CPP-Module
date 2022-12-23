#include "Bureaucrat.hpp"

int main()
{
	{
		try
		{
			Bureaucrat H("H", -1);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
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
			std::cout << e.what() << std::endl;
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
			std::cout << e.what() << std::endl;
		}
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
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}
