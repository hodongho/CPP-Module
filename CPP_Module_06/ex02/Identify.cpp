#include "Identify.hpp"

Base*	generate(void)
{
	Base*	ret = 0;
	int		random = time(0) % 3;

	std::cout << "Generate ";

	if (random == 0)
	{
		ret = new A();
		std::cout << "A" << std::endl;
	}
	else if (random == 1)
	{
		ret = new B();
		std::cout << "B" << std::endl;
	}
	else if (random == 2)
	{
		ret = new C();
		std::cout << "C" << std::endl;
	}
	return (ret);
}

void	identify(Base* p)
{
	std::cout << "This pointer's actual type is ";

	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void	identify(Base& p)
{
	std::cout << "This reference's actual type is ";

	try
	{
		A& a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		static_cast<void>(a);
	}
	catch (std::bad_cast exception)
	{
		try
		{
			B& b = dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
			static_cast<void>(b);
		}
		catch (std::bad_cast exception)
		{
			try
			{
				C& c = dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
				static_cast<void>(c);
			}
			catch(std::bad_cast exception)
			{
			}
		}
	}
}
