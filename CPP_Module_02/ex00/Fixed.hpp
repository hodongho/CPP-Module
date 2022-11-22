#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
	private:
		int					fixedPoint;
		static const int	fractionalBit = 8;
	public:
		Fixed();
		Fixed(const Fixed& _Fixed);
		Fixed& operator=(const Fixed& _Fixed);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};


#endif
