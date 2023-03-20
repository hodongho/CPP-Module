#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <map>


class BitcoinExchange
{
private:
	std::fstream						DB;
	std::fstream						InputDB;
	std::map<std::string, float>		DBMap;

public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange& copy);

	BitcoinExchange&	operator=(BitcoinExchange& copy);

	~BitcoinExchange();

};

void printError(std::string msg);

#endif
