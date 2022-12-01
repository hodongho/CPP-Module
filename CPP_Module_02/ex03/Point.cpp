#include "Point.hpp"

Point::Point()
		:x(0), y(0)
{
}

Point::Point(const float _x, const float _y)
		:x(_x), y(_y)
{
}

Point::Point(const Point& copy)
		:x(copy.getX()), y(copy.getY())
{
}

Point& Point::operator=(const Point& copy)
{
	return (*this);
}

Point::~Point()
{
}

Fixed	Point::getX() const
{
	return (x);
}

Fixed	Point::getY() const
{
	return (y);
}

Point	Point::operator-(const Point& point) const
{
	return (Point((getX() - point.getX()).toFloat(), (getY() - point.getY()).toFloat()));
}

