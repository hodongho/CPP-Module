#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <vector>

class BitcoinExchange
{
private:
	std::fstream					DB;
	std::fstream					input_DB;
	std::vector<std::string>		DB_vec;

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& copy);

	BitcoinExchange&	operator=(const BitcoinExchange& copy);

	~BitcoinExchange();

	void	parseInput(const char* input_file);
	void	checkDate(std::string date);
	void	checkPrice(std::string price_str);
};

void printError(std::string msg);

#endif
