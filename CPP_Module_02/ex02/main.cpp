#include "Fixed.hpp"

int main()
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	//                   a                      //
	std::cout << a << std::endl;
	//             pre-increment a              //
	std::cout << ++a << std::endl;
	//          after pre-increment a           //
	std::cout << a << std::endl;
	//            post-increment a              //
	std::cout << a++ << std::endl;
	//          after post-increment a          //
	std::cout << a << std::endl;
	//                   b                      //
	std::cout << b << std::endl;
	//            maximum value of a b          //
	std::cout << Fixed::max( a, b ) << std::endl;
	//            minimum value of a b          //
	std::cout << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;
	//                   a                      //
	std::cout << a << std::endl;
	//             pre-decrement a              //
	std::cout << --a << std::endl;
	//          after pre-decrement a           //
	std::cout << a << std::endl;
	//            post-decrement a              //
	std::cout << a-- << std::endl;
	//          after post-decrement a          //
	std::cout << a << std::endl;
	std::cout << std::endl;

	//Comparison
	bool	ret = 0;
	Fixed	c(b);

	std::cout << "a: " << a << " b: " << b << " c: " << c << std::endl;
	ret = a >= b;
	std::cout << ret << std::endl;
	ret = a <= b;
	std::cout << ret << std::endl;

	ret = b <= c;
	std::cout << ret << std::endl;
	ret = b >= c;
	std::cout << ret << std::endl;

	ret = b == c;
	std::cout << ret << std::endl;
	ret = b != c;
	std::cout << ret << std::endl;
	std::cout << std::endl;

	//Arithmetic
	std::cout << "a: " << a << " b: " << b << " c: " << c << std::endl;
	return (0);
}
