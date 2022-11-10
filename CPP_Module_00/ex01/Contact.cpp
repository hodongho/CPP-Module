#include <iostream>
#include <iomanip>
#include "Contact.hpp"

bool	Contact::SetIndex(int _index)
{
	index = _index + 1;
	return (true);
}

bool	Contact::SetFirstName(std::string _first_name)
{
	first_name = _first_name;
	return (true);
}

bool	Contact::SetLastName(std::string _last_name)
{
	last_name = _last_name;
	return (true);
}

bool	Contact::SetNickname(std::string _nickname)
{
	nickname = _nickname;
	return (true);
}

bool	Contact::SetPhoneNumber(std::string _phone_number)
{
	int	digit = 0;

	for (int i = 0; _phone_number[i]; i++)
	{
		if (isdigit(_phone_number[i]))
		{
			digit++;
		}
		else if (_phone_number[i] != '-')
			return (false);
	}
	if (digit == 0)
		return (false);
	if (_phone_number.length() < 11)
		return (false);
	phone_number = _phone_number;
	return (true);
}

bool	Contact::SetDarkestSecret(std::string _darkest_secret)
{
	darkest_secret = _darkest_secret;
	return (true);
}

bool	Contact::AddContact(std::string input, int i)
{
	if (i == 0)
		SetFirstName(input);
	else if (i == 1)
		SetLastName(input);
	else if (i == 2)
		SetNickname(input);
	else if (i == 3)
	{
		if (SetPhoneNumber(input) == false)
			return (false);
	}
	else if (i == 4)
		SetDarkestSecret(input);
	return (true);
}

void	Contact::PrintColumn(std::string &str)
{
	std::string tmp;

	if (str.length() > 10)
	{
		tmp = str;
		tmp.resize(10);
		tmp[9] = '.';
		std::cout << std::setw(10) << std::right << tmp;
	}
	else
		std::cout << std::setw(10) << std::right << str;
	if (&str != &nickname)
		std::cout << "|";
}

void	Contact::Search()
{
	std::string tmp;

	if (index == 0)
		return ;
	std::cout << std::setw(10) << std::right << index << "|";
	PrintColumn(first_name);
	PrintColumn(last_name);
	PrintColumn(nickname);
	std::cout << std::endl;
}

void	Contact::Display()
{
	std::cout << "First Name : " << first_name << std::endl;
	std::cout << "Last Name : " << last_name << std::endl;
	std::cout << "Nickname : " << nickname << std::endl;
	std::cout << "Phone Number : " << phone_number << std::endl;
	std::cout << "Darkest Secret : " << darkest_secret << std::endl;
}
