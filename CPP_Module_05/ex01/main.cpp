#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << std::endl << "--------------------Start!--------------------" << std::endl << std::endl;

	{
		try
		{
			Form	H("H", 0, 0);
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
			Form	L("L", 151, 151);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << std::endl << "----------------------------------------------" << std::endl << std::endl;

	{
		Bureaucrat	A("A", 1);

		Form		Top("Top", 1, 1);
		Form		Middle1("Middle1", 50, 50);
		Form		Middle2("Middle2", 100, 100);
		Form		Bottom("Bottom", 150, 150);

		std::cout << A << std::endl;
		try
		{
			A.signForm(Top);
			A.signForm(Middle1);
			A.signForm(Middle2);
			A.signForm(Bottom);
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << std::endl;

		try
		{
			A.signForm(Bottom);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << std::endl << "----------------------------------------------" << std::endl << std::endl;

	{
		Bureaucrat B("B", 75);

		Form		Top("Top", 1, 1);
		Form		Middle1("Middle1", 50, 50);
		Form		Middle2("Middle2", 100, 100);
		Form		Bottom("Bottom", 150, 150);

		std::cout << B << std::endl;
		try
		{
			B.signForm(Top);
			B.signForm(Middle1);
			B.signForm(Middle2);
			B.signForm(Bottom);
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << std::endl;

		try
		{
			B.signForm(Bottom);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << std::endl << "----------------------------------------------" << std::endl << std::endl;

	{
		Bureaucrat C("C", 150);

		Form		Top("Top", 1, 1);
		Form		Middle1("Middle1", 50, 50);
		Form		Middle2("Middle2", 100, 100);
		Form		Bottom("Bottom", 150, 150);

		std::cout << C << std::endl;
		try
		{
			C.signForm(Top);
			C.signForm(Middle1);
			C.signForm(Middle2);
			C.signForm(Bottom);
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << std::endl;

		try
		{
			C.signForm(Bottom);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return (0);
}
