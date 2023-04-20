#include "BitcoinExchange.hpp"

int main (int argc, char *argv[])
{
	std::cout << WHI;

	if (argc != 2)
		printError("could not open file.");

	BitcoinExchange	BE;

	BE.run(argv[1]);

	return (0);
}
