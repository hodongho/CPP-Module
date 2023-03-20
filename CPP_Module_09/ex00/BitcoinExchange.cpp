#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
:DB("data.csv", std::fstream::in)
{
	std::string date;
	std::string priceStr;
	float		price;

	while(!DB.eof())
	{
		std::getline(DB, date, ',');
		std::getline(DB, priceStr);
		price = atof(priceStr.c_str());
		DBMap.insert({date, price});
	}
}

BitcoinExchange::BitcoinExchange(BitcoinExchange& copy)
{
	if (this != &copy)
		*this = copy;
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange& copy)
{
	(void)copy;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

void	printError(std::string msg)
{
	std::cerr << msg << std::endl;
	exit(1);
}
