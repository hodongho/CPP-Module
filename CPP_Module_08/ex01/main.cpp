#include <iostream>
#include "Span.hpp"
#include <vector>

int main()
{
	std::cout << "\n-----Basic Test-----\n" << std::endl;

	{
		Span sp = Span(20);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl << std::endl;

		sp.addNumber(1);
		sp.addNumber(4);
		sp.addNumber(17);
		sp.addNumber(31);
		sp.addNumber(12);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	std::cout << "\n-----addNumber() Test-----\n" << std::endl;

	{
		Span sp = Span(20);
		std::vector<int> vec(5, 42);

		sp.addNumber(vec.begin(), vec.end());

		std::multiset<int>::iterator	iter;
		iter = sp.getStore().begin();

		while(iter != sp.getStore().end())
		{
			std::cout << *iter << std::endl;
			iter++;
		}
	}
	std::cout << "\n-----Exception Test-----\n" << std::endl;

	{
		Span sp;

		try
		{
			sp.addNumber(123);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			sp.shortestSpan();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			sp.longestSpan();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	return (0);
}
