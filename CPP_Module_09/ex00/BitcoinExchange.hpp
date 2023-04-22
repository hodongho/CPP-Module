#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <map>

# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define BRW "\e[0;33m"
# define BLU "\e[0;34m"
# define PUP "\e[0;35m"
# define CYN "\e[0;36m"
# define WHI "\e[0;37m"

class BitcoinExchange
{
private:
	std::map<std::string, float>	basic_DB_map;

	bool	validateInput(const std::string& line, std::string& date, std::string& value);
	bool	divideByDelimiter(const std::string& line, std::string& date, std::string& value);
	bool	validateDate(const std::string& date);
	bool	validateValue(const std::string& value);

	void	exchangeData(std::string& date, std::string& value);

public:
	BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange& copy);

	BitcoinExchange&	operator=(const BitcoinExchange& copy);

	~BitcoinExchange(void);

	void	run(const char* input_file_name);
};

void printError(std::string msg);
bool printErrorMessage(std::string msg);

#endif
