#include <iostream>

char	*str_upper(char *str)
{
	int	i;

	std::cout << &str << std::endl;
	i = 0;
	while (str[i])
	{
		str[i] = toupper(str[i]);
		i++;
	}
	return(str);
}

int	main(int argc, char *argv[])
{
	std::string str;

	std::cout << &str << std::endl;
	str.clear();
	if (argc < 2)
		str = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for(int i = 1; i < argc; i++)
		str += str_upper(argv[i]);
	std::cout << str << std::endl;
	return (0);
}
