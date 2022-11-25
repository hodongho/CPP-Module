#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	private:
		int					fixedPoint;
		static const int	fractionalBit = 8;
	public:
		Fixed();
		Fixed(const Fixed& copy);
		Fixed(const int	_fixedPoint);
		Fixed(const float _fixedPoint);

		Fixed& operator=(const Fixed& copy);

		//Comparison//
		bool	operator>(const Fixed& _Fixed) const;
		bool	operator<(const Fixed& _Fixed) const;
		bool	operator>=(const Fixed& _Fixed) const;
		bool	operator<=(const Fixed& _Fixed) const;
		bool	operator==(const Fixed& _Fixed) const;
		bool	operator!=(const Fixed& _Fixed) const;

		//Arithmetic//
		Fixed	operator+(const Fixed& _Fixed) const;
		Fixed	operator-(const Fixed& _Fixed) const;
		Fixed	operator*(const Fixed& _Fixed) const;
		Fixed	operator/(const Fixed& _Fixed) const;

		//Increase and Decrease//
		Fixed&	operator++(void);
		const Fixed	operator++(int);
		Fixed&	operator--(void);
		const Fixed	operator--(int);

		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void)	const;
		static Fixed&	min(Fixed& f1, Fixed& f2);
		static const Fixed&	min(const Fixed& f1, const Fixed& f2);
		static Fixed&	max(Fixed& f1, Fixed& f2);
		static const Fixed&	max(const Fixed& f1, const Fixed& f2);
};

std::ostream& operator<<(std::ostream &out, const Fixed& _Fixed);

#endif
