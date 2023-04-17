#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
:DB("data.csv", std::fstream::in)
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
:DB("data.csv", std::fstream::in)
{
	if (this != &copy)
		*this = copy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy)
{
	(void)copy;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

void	printError(std::string msg)
{
	std::cerr << "Error: " << msg << std::endl;
	exit(1);
}

void	BitcoinExchange::parseInput(const char* input_file_name)
{
}


void	BitcoinExchange::checkDate(std::string date)
{
}

void	BitcoinExchange::checkPrice(std::string price_str)
{
	(void)price_str;
}
