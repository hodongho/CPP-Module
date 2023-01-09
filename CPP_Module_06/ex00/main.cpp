#include "Converter.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Wrong arguments" << std::endl;
		return (1);
	}

	std::string str(argv[1]);

	if (str.length() == 0)
	{
		std::cerr << "Wrong arguments" << std::endl;
		return (1);
	}

	std::cout << std::fixed;
	std::cout.precision(1);

	Converter converter(str);
	converter.print();
	return (0);
}
