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
	for(int	i = 0; i < _first_name[i]; i++)
	{
		if (!isalpha(_first_name[i]))
			return (false);
	}
	first_name = _first_name;
	return (true);
}

bool	Contact::SetLastName(std::string _last_name)
{
	for(int	i = 0; i < _last_name[i]; i++)
	{
		if (isdigit(_last_name[i]))
			return (false);
	}
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
	bool	ret;

	ret = true;
	if (i == 0)
		ret = SetFirstName(input);
	else if (i == 1)
		ret = SetLastName(input);
	else if (i == 2)
		ret = SetNickname(input);
	else if (i == 3)
		ret = SetPhoneNumber(input);
	else if (i == 4)
		ret = SetDarkestSecret(input);
	return (ret);
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
	std::cout << std::endl << std::setw(10) << std::right << index << "|";
	PrintColumn(first_name);
	PrintColumn(last_name);
	PrintColumn(nickname);
	std::cout << std::endl << std::endl;
}

void	Contact::Display()
{
	std::cout << "First Name : " << first_name << std::endl;
	std::cout << "Last Name : " << last_name << std::endl;
	std::cout << "Nickname : " << nickname << std::endl;
	std::cout << "Phone Number : " << phone_number << std::endl;
	std::cout << "Darkest Secret : " << darkest_secret << std::endl;
}
