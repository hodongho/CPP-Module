#include "Point.hpp"

int main()
{
	Point	a(0, 0);
	Point	b(0, 7);
	Point	c(3.4, 1.3);
	Point	d(1.3, 3.2333);
	Point	e(5.08, 5.84);
	Point	f(2.2, 5.32);

	bool	ret1;
	bool	ret2;
	bool	ret3;

	ret1 = bsp(a, b, c, d);
	ret2 = bsp(a, b, c, e);
	ret3 = bsp(a, b, c, f);

	std::cout << ret1 << std::endl;
	std::cout << ret2 << std::endl;
	std::cout << ret3 << std::endl;
	return (0);
}
