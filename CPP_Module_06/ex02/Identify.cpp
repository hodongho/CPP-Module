#include "Identify.hpp"

Base*	generate(void)
{
	Base*	ret;
	int		random = rand() % 3;

	if (random == 0)
		ret = new A();
	else if (random == 1)
		ret = new B();
	else if (random == 2)
		ret = new C();
	return (ret);
}

void	identify(Base* p)
{
	std::cout << "This pointer's actual type is " << std::endl;

	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void	identify(Base& p)
{
	std::cout << "This reference's actual type is " << std::endl;

	if (dynamic_cast<A&>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B&>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C&>(p))
		std::cout << "C" << std::endl;
}
