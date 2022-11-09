#include <iostream>
#include "PhoneBook.hpp"

int	main()
{
	PhoneBook PhoneBook;
	std::string	cmd;

	PhoneBook.init();
	while (1)
	{
		std::cout << "Please enter commands : ";
		getline(std::cin, cmd);
		if (cmd == "ADD")
			PhoneBook.add_contacts();
		else if (cmd == "SEARCH")
			PhoneBook.search();
		else if (cmd == "EXIT")
			break ;
	}
	return (0);
}
