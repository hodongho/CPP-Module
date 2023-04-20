#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::ifstream		basic_DB("data.csv");
	std::string			date;
	std::string			value;
	std::string			buf;

	if (!basic_DB.is_open())
		printError("could not open file.");

	std::getline(basic_DB, buf);
	while (true)
	{
		std::getline(basic_DB, date, ',');
		std::getline(basic_DB, value);

		if (basic_DB.eof())
			break ;

		this->basic_DB_map[date] = atof(value.c_str());
		// std::cout << BLU << date << " " << PUP << this->basic_DB_map[date] << WHI << std::endl;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
{
	*this = copy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy)
{
	if (this != &copy)
	{
		this->basic_DB_map = copy.basic_DB_map;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

void	BitcoinExchange::run(const char* input_file_name)
{
	this->parseInput(input_file_name);
}

void	BitcoinExchange::parseInput(const char* input_file_name)
{
	std::ifstream		input_DB(input_file_name);
	std::string			date;
	std::string			value;
	std::string			buf;

	if (!input_DB.is_open())
		printError("could not open file.");

	std::getline(input_DB, buf);
	while (true)
	{
		std::getline(input_DB, buf);

		if (input_DB.eof())
			break ;

		if (this->validateInput(buf, date, value) == false)
			continue ;

		// std::cout << BLU << date << " " << PUP << atof(value.c_str()) << WHI << std::endl;
	}
}

bool	BitcoinExchange::validateInput(const std::string& line, std::string& date, std::string& value)
{
	if (this->divideByDelimiter(line, date, value) == false)
		return (false);
	if (this->validateDate(date) == false)
		return (false);
	if (this->validateValue(value) == false)
		return (false);
	return (true);
}

bool	BitcoinExchange::divideByDelimiter(const std::string& line, std::string& date, std::string& value)
{
	size_t	delimiterPos = line.find(" | ");

	if (delimiterPos == std::string::npos)
		return (printErrorMessage("bad input => " + line));

	date = line.substr(0, delimiterPos);
	value = line.substr(delimiterPos + 3);

	return (true);
}

bool	BitcoinExchange::validateDate(const std::string& date)
{
	if (date.size() != 10)
		return (printErrorMessage("bad date => " + date));

	for (size_t index = 0; index < date.size(); index++)
	{
		if ((index == 4 || index == 7) && date[index] == '-')
			continue ;
		if (!isdigit(date[index]))
			return (printErrorMessage("bad date => " + date));
	}

	int	year = atoi(date.substr(0, 4).c_str());
	int	month = atoi(date.substr(5, 2).c_str());
	int	day = atoi(date.substr(8, 2).c_str());

	if (month > 12 ||
		((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 ||
			month == 10 || month == 12) && day > 31) ||
		(((month == 4 || month == 6 || month == 9 || month == 11)
			&& day > 30)))
		return (printErrorMessage("bad date => " + date));

	if (month == 2)
	{
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			if (day > 29)
				return (printErrorMessage("bad date => " + date));
		}
		else if (day > 28)
				return (printErrorMessage("bad date => " + date));
	}

	// std::cout << GRN << date + " => " << WHI;

	return (true);
}

bool	BitcoinExchange::validateValue(const std::string& value)
{
	size_t	dotCount = 0;

	double	tmp_value = atof(value.c_str());

	if (tmp_value <= 0)
		return (printErrorMessage("not a positive number."));
	else if (tmp_value >= 1000)
		return (printErrorMessage("too large a number."));

	for (size_t index = 0; index < value.size(); index++)
	{
		if (value[index] == '.')
		{
			if (dotCount != 0)
				return (printErrorMessage("bad value => " + value));
			dotCount++;
			continue ;
		}

		if (!isdigit(value[index]))
			return (printErrorMessage("bad value => " + value));
	}


	return (true);
}



void	printError(std::string msg)
{
	std::cerr << RED << "Error: " << msg << std::endl;
	exit(1);
}

bool	printErrorMessage(std::string msg)
{
	std::cout << RED << "Error: " << msg << WHI << std::endl;
	return (false);
}
