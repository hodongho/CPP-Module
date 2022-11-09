#include <iostream>
#include "PhoneBook.hpp"

void	PhoneBook::init()
{
	memset(Contacts, 0, sizeof(Contacts));
	index = 0;
}

void	PhoneBook::add_contacts()
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
		Contacts[index].add_contact(input, i);
	}
	Contacts[index].set_index(index);
	index++;
	if (index == 8)
		index = 0;
}

void	PhoneBook::search()
{
	std::string	input;
	int			index;

	for(int	i = 0; i < 8; i++)
		Contacts[i].search();
	std::cout << "Please select any index : ";
	getline(std::cin, input);
	index = stoi(input);
	if (index < 1 || index > 8)
	{
		std::cout << "Wrong index" << std::endl;
		return ;
	}
	Contacts[index - 1].display();
}
