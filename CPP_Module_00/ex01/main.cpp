#include <iostream>
#include "PhoneBook.hpp"

int	main()
{
	PhoneBook PhoneBook;
	std::string	cmd;

	while (1)
	{
		std::cout << "Please enter commands : ";
		getline(std::cin, cmd);
		if (cmd == "ADD")
			PhoneBook.AddContact();
		else if (cmd == "SEARCH")
			PhoneBook.Search();
		else if (cmd == "EXIT")
			break ;
	}
	return (0);
}
