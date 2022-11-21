#include "Harl.hpp"

void	Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl
		<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl
		<< "I really do!"
		<< std::endl << std::endl;
}

void	Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl
		<< "I cannot believe adding extra bacon costs more money." << std::endl
		<< "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
		<< std::endl << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl
		<< "I think I deserve to have some extra bacon for free." << std::endl
		<< "I’ve been coming for years whereas you started working here since last month."
		<< std::endl << std::endl;
}

void	Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl
		<< "This is unacceptable! I want to speak to the manager now."
		<< std::endl << std::endl;
}

int	CompareLevel(std::string level)
{
	std::string	_level[4] =
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	for (int i = 0; i < 4; i++)
	{
		if (level == _level[i])
			return (i);
	}
	return (-1);
}

void	Harl::complain( std::string level )
{
	void	(Harl::*f[4])(void) = {0, };
	int		i = 0;

	switch (CompareLevel(level))
	{
		case DEBUG:
		{
			f[i] = &Harl::debug;
			i++;
		}
		case INFO:
		{
			f[i] = &Harl::info;
			i++;
		}
		case WARNING:
		{
			f[i] = &Harl::warning;
			i++;
		}
		case ERROR:
		{
			f[i] = &Harl::error;
			i++;
			break ;
		}
		default:
		{
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			return ;
		}
	}
	for (int i = 0; f[i]; i++)
		(this->*f[i])();
}

