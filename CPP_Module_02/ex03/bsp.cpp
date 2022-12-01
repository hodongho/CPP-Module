#include "Point.hpp"

Fixed	outer_product(Point a, Point b, Point c)
{
	return ((b.getX() - a.getX()) * (c.getY() - a.getY())
		- (c.getX() - a.getX()) * (b.getY() - a.getY()));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	bool	ret = false;
	Fixed	min_x = 0;
	Fixed	min_y = 0;
	Fixed	max_x = 0;
	Fixed	max_y = 0;

	min_x = Fixed::min(a.getX(), b.getX());
	min_x = Fixed::min(min_x, c.getX());

	min_y = Fixed::min(a.getY(), b.getY());
	min_y = Fixed::min(min_y, c.getY());

	max_x = Fixed::max(a.getX(), b.getX());
	max_x = Fixed::max(max_x, c.getX());

	max_y = Fixed::max(a.getY(), b.getY());
	max_y = Fixed::max(max_y, c.getY());

	std::cout << min_x << " " << min_y << " " << max_x << " " << max_y << std::endl;
	if (point.getX() < min_x || point.getY() < min_y || point.getX() > max_x || point.getY() > max_y)
		return (ret);

	Fixed	abp = outer_product(a, b, point);
	Fixed	bcp = outer_product(b, c, point);
	Fixed	cap = outer_product(c, a, point);

	if (abp <= 0 && bcp <= 0 && cap <= 0)
		ret = true;
	if (abp >= 0 && bcp >= 0 && cap >= 0)
		ret = true;
	return (ret);
}
