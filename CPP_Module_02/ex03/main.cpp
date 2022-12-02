#include "Point.hpp"

int main()
{
	Point	a;
	Point	b(0, 7);
	Point	c(3.4, 1.3);
	Point	d(1.3, 3.2333);
	Point	e(5.08, 5.84);
	Point	f(2.2, 5.32);
	Point	g(-2, -2);
	Point	h(0, 4);


	bool	ret1;
	bool	ret2;
	bool	ret3;
	bool	ret4;
	bool	ret5;

	ret1 = bsp(a, b, c, d);
	ret2 = bsp(b, c, c, e);
	ret3 = bsp(a, b, c, f);
	ret4 = bsp(a, b, c, g);
	ret5 = bsp(a, b, c, h);

	std::cout << ret1 << std::endl;
	std::cout << ret2 << std::endl;
	std::cout << ret3 << std::endl;
	std::cout << ret4 << std::endl;
	std::cout << ret5 << std::endl;
	return (0);
}
