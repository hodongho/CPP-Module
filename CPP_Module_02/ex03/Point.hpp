#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point(void);
		Point(const float _x, const float _y);
		Point(const Point& copy);

		Point&	operator=(const Point& copy);

		~Point();

		Fixed	getX() const;
		Fixed	getY() const;
		Point	operator-(const Point& point) const;
};

bool	bsp( Point const a, Point const b, Point const c, Point const point);

#endif
