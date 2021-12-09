#ifndef __FIXED_H__
#define __FIXED_H__

#include <iostream>

class Fixed
{
	public:
	Fixed();
	Fixed(const Fixed &fixed);
	~Fixed();
	Fixed& operator=(const Fixed &fixed);

	int	getRawBits(void) const;
	void setRawBits(int const raw);

	private:
	int fixedPoint;
	static const int fractionalBits = 8;
};

#endif