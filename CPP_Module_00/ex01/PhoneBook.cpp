#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	memset(Contacts, 0, sizeof(Contacts));
	index = 0;
}

void	PhoneBook::AddContact()
{
	std::string		mes[5] = {
		"First Name : ",
		"Last Name : ",
		"Nickname : ",
		"Phone Number : ",
		"Darkest Secret : "
	};
	std::string	input;

	for (int i = 0; i < 5; i++)
	{
		std::cout << mes[i];
		getline(std::cin, input);
		if (input.empty() == true)
		{
			std::cout << std::endl << "-----Input is empty!-----" << std::endl << std::endl;
			i--;
		}
		if (Contacts[index].AddContact(input, i) == false)
		{
			std::cout << std::endl << "-----Wrong input!-----" << std::endl << std::endl;
			i--;
		}
	}
	Contacts[index].SetIndex(index);
	index++;
	if (index == 8)
		index = 0;
}

void	PhoneBook::Search()
{
	std::string	input;

	while(1)
	{
		for(int	i = 0; i < index; i++)
			Contacts[i].Search();
		std::cout << "Please select any index : ";
		getline(std::cin, input);
		if (input.empty() == true)
		{
			std::cout << std::endl << "-----Input is empty!-----" << std::endl << std::endl;
			continue ;
		}
		if (input[1] != 0 || input[0] < '1' || input[0] > '8' || input[0] > index + '0')
		{
			std::cout << std::endl << "-----Wrong index!-----" << std::endl << std::endl;
			continue ;
		}
		break ;
	}
	Contacts[input[0] - '0' - 1].Display();
}
