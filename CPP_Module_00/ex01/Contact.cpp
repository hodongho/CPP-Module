#include <iostream>
#include <iomanip>
#include "Contact.hpp"

void	Contact::set_index(int _index)
{
	index = _index + 1;
}

void	Contact::add_contact(std::string input, int i)
{
	if (i == 0)
		first_name = input;
	else if (i == 1)
		last_name = input;
	else if (i == 2)
		nickname = input;
	else if (i == 3)
		phone_number = input;
	else if (i == 4)
		darkest_secret = input;
}

void	print_column(std::string str)
{
	std::string tmp;

	if (str.length() > 10)
	{
		tmp = str;
		tmp.resize(10);
		tmp[9] = '.';
		std::cout << std::setw(10) << std::right << tmp << "|";
	}
	else
		std::cout << std::setw(10) << std::right << str << "|";
}

void	Contact::search()
{
	std::string tmp;

	if (index == 0)
		return ;
	std::cout << std::setw(10) << std::right << index << "|";
	print_column(first_name);
	print_column(last_name);
	print_column(nickname);
	std::cout << std::endl;
}

void	Contact::display()
{
	std::cout << "First Name : " << first_name << std::endl;
	std::cout << "Last Name : " << last_name << std::endl;
	std::cout << "Nickname : " << nickname << std::endl;
	std::cout << "Phone Number : " << phone_number << std::endl;
	std::cout << "Darkest Secret : " << darkest_secret << std::endl;
}
