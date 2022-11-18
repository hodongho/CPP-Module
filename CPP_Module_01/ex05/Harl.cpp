#include "Harl.hpp"

void	Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl
		<< "I really do!"
		<< std::endl;
}

void	Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl
		<< "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
		<< std::endl;
}

void	Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl
		<< "I’ve been coming for years whereas you started working here since last month."
		<< std::endl;
}

void	Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now."
		<< std::endl;
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
	void	(Harl::*f)(void);

	switch (CompareLevel(level))
	{
		case DEBUG:
		{
			f = &Harl::debug;
			break ;
		}
		case INFO:
		{
			f = &Harl::info;
			break ;
		}
		case WARNING:
		{
			f = &Harl::warning;
			break ;
		}
		case ERROR:
		{
			f = &Harl::error;
			break ;
		}
		default:
		{
			std::cerr << "Wrong level!" << std::endl;
			return ;
		}
	}
	(this->*f)();
}

