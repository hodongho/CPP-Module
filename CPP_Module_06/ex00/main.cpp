#include <iostream>

void	print_char(char *str)
{
	std::cout <<  "char: ";

	int i = atoi(str);
	std::cout << i << " " << errno << std::endl;
	if (i < 32 || i > 126)
	{
		if (errno != 0)
			std::cout << "impossible" << std::endl;
		if ((i >= 0 && i < 32) || i == 127)
		{
			std::cout << "Non displayable" << std::endl;
			return ;
		}
		return ;
	}

	std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
}

void	print_int(char *str)
{
	std::cout << "int: " << str << std::endl;
}

void	print_float(char *str)
{
	std::cout << "float: " << str << std::endl;
}

void	print_double(char *str)
{
	std::cout << "double: " << str << std::endl;
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Wrong arguments" << std::endl;
		return (1);
	}

	print_char(argv[1]);
	print_int(argv[1]);
	print_float(argv[1]);
	print_double(argv[1]);
	return (0);
}
