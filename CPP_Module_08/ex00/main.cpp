#include "easyfind.hpp"
#include <iostream>

int main()
{
	std::vector<int> vec;

	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i);
	}

	try
	{
		int i = easyfind(vec, 2);
		std::cout << i << std::endl;
		i = easyfind(vec, 6);
		std::cout << i << std::endl;
		i = easyfind(vec, 10);
		std::cout << i << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::deque<int> deq;
	for (int i = 0; i < 10; ++i)
	{
		deq.push_back(i);
		deq.push_front(i);
	}
	try
	{
		int i = easyfind(deq, 0);
		std::cout << i << std::endl;
		i = easyfind(deq, 7);
		std::cout << i << std::endl;
		i = easyfind(deq, -1);
		std::cout << i << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
