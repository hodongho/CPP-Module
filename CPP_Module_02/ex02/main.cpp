#include "Fixed.hpp"

int main()
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << std::endl;
	std::cout << "-----a-----" << std::endl << std::endl;
	std::cout << a << std::endl << std::endl;
	std::cout << "-----pre-increment a-----" << std::endl << std::endl;
	std::cout << ++a << std::endl << std::endl;
	std::cout << "-----after pre-increment a-----" << std::endl << std::endl;
	std::cout << a << std::endl << std::endl;
	std::cout << "-----post-increment a-----" << std::endl << std::endl;
	std::cout << a++ << std::endl << std::endl;
	std::cout << "-----after post-increment a-----" << std::endl << std::endl;
	std::cout << a << std::endl << std::endl;

	std::cout << "-----b-----" << std::endl << std::endl;
	std::cout << b << std::endl << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
	return (0);
}
