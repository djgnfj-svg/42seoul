#ifndef __FIXED_H__
#define __FIXED_H__

#include <iostream>
# include <cmath>

class Fixed
{
	public:
	Fixed();
	Fixed(const int x);
	Fixed(float const f);
	Fixed(const Fixed &fixed);
	~Fixed();
	Fixed& operator=(const Fixed &fixed);

	int	getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
	
	private:
	int fixedPoint;
	static const int fractionalBits = 8;
};

std::ostream& operator<<(std::ostream& out, const Fixed& src);
#endif