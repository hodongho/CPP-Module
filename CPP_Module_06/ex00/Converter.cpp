#include "Converter.hpp"

Converter::Converter()
	:str(""), type(OTHER)
{
}

Converter::Converter(std::string str)
	:str(str), type(OTHER)
{
	setType();
}

Converter::Converter(Converter& copy)
{
	*this = copy;
}

Converter& Converter::operator=(Converter& copy)
{
	if (this != &copy)
	{
		str = copy.getStr();
		type = copy.getType();
	}
	return (*this);
}

Converter::~Converter()
{
}

const std::string&	Converter::getStr() const
{
	return (str);
}

const Type&	Converter::getType() const
{
	return (type);
}

void	Converter::isChar()
{
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		type = CHAR;
}

void	Converter::isInt()
{
	int		sign = 0;

	if (str[0] == '+' || str[0] == '-')
		sign = 1;
	if (!sign && (!isdigit(str[0]) || str.length() > 10))
		return ;
	if (sign && (str.length() == 1 || str.length() > 11))
		return ;
	for (size_t i = sign; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return ;
	}
	type = INT;
}

void	Converter::isFloat()
{
	int		sign = 0;
	bool	dot = 0;

	if (str[0] == '+' || str[0] == '-')
		sign = 1;
	if (!sign && !isdigit(str[0]))
		return ;
	if (sign && str.length() == 1)
		return ;
	if (str[str.length() - 1] != 'f')
		return ;
	for (size_t i = sign; i < str.length() - 1; i++)
	{
		if (!isdigit(str[i]))
		{
			if (str[i] == '.')
			{
				if (dot == true || i == str.length() - 2)
					return ;
				dot = true;
			}
			else
				return ;
		}
	}
	if (dot == false)
		return ;
	type = FLOAT;
}

void	Converter::isDouble()
{
	int		sign = 0;
	bool	dot = 0;

	if (str[0] == '+' || str[0] == '-')
		sign = 1;
	if (!sign && !isdigit(str[0]))
		return ;
	if (sign && str.length() == 1)
		return ;
	for (size_t i = sign; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
		{
			if (str[i] == '.')
			{
				if (dot == true || i == str.length() - 1)
					return ;
				dot = true;
			}
			else
				return ;
		}
	}
	type = DOUBLE;
}

void	Converter::setType()
{
	if (!str.compare("nanf") || !str.compare("nan"))
		return ;
	if (!str.compare("inff") || !str.compare("-inff"))
		type = FLOAT;
	else if (!str.compare("inf") || !str.compare("-inf"))
		type = DOUBLE;
	if (type == OTHER)
		isChar();
	if (type == OTHER)
		isInt();
	if (type == OTHER)
		isFloat();
	if (type == OTHER)
		isDouble();
}

void	Converter::printChar()
{
	char	literalValue = str[1];
	int		upValue = str[1];

	std::cout << "char: ";
	if (upValue < CHAR_MIN || upValue > CHAR_MAX)
		std::cout << "impossible" << std::endl;
	else if ((upValue < 32 && (upValue < 9 || upValue > 13)) || upValue > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << literalValue << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(literalValue) << std::endl;
	std::cout << "float: " << static_cast<float>(literalValue) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(literalValue) << std::endl;
}

void	Converter::printInt()
{
	int		literalValue = atoi(str.c_str());
	double	upValue = strtod(str.c_str(), 0);

	std::cout << "char: ";
	if (upValue < CHAR_MIN || upValue > CHAR_MAX)
		std::cout << "impossible" << std::endl;
	else if ((upValue < 32 && (upValue < 9 || upValue > 13)) || upValue > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(literalValue) << "'" << std::endl;

	std::cout << "int: ";
	if (upValue < INT_MIN || upValue > INT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << literalValue << std::endl;

	if (static_cast<double>(literalValue) == upValue)
	{
		std::cout << "float: " << static_cast<float>(literalValue) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(literalValue) << std::endl;
	}
	else
	{
		std::cout << "float: " << static_cast<float>(upValue) << "f" << std::endl;
		std::cout << "double: " << upValue << std::endl;
	}

}

void	Converter::printFloat()
{
	float literalValue = strtof(str.c_str(), 0);
	double upValue = strtod(str.c_str(), 0);

	std::cout << "char: ";
	if (upValue < CHAR_MIN || upValue > CHAR_MAX)
		std::cout << "impossible" << std::endl;
	else if ((upValue < 32 && (upValue < 9 || upValue > 13)) || upValue > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(literalValue) << "'" << std::endl;

	std::cout << "int: ";
	if (upValue < INT_MIN || upValue > INT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(literalValue) << std::endl;

	std::cout << "float: " << literalValue << "f" << std::endl;
	if (static_cast<double>(literalValue) == upValue)
		std::cout << "double: " << static_cast<double>(literalValue) << std::endl;
	else
		std::cout << "double: " << upValue << std::endl;
}

void	Converter::printDouble()
{
	double literalValue = strtod(str.c_str(), 0);

	std::cout << "char: ";
	if (literalValue < CHAR_MIN || literalValue > CHAR_MAX)
		std::cout << "impossible" << std::endl;
	else if ((literalValue < 32 && (literalValue < 9 || literalValue > 13)) || literalValue > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(literalValue) << "'" << std::endl;

	std::cout << "int: ";
	if (literalValue < INT_MIN || literalValue > INT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(literalValue) << std::endl;

	std::cout << "float: " << static_cast<float>(literalValue) << "f" << std::endl;
	std::cout << "double: " << literalValue << std::endl;
}

void	Converter::printOther()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

void	Converter::print()
{
	switch (type)
	{
		case CHAR:
		{
			printChar();
			break ;
		}
		case INT:
		{
			printInt();
			break ;
		}
		case FLOAT:
		{
			printFloat();
			break ;
		}
		case DOUBLE:
		{
			printDouble();
			break ;
		}
		case OTHER:
		{
			printOther();
			break ;
		}
	}
}

