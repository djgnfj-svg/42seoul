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
	Fixed&	operator=( const Fixed &fixed );
	bool	operator>( const Fixed &fixed ) const;
	bool	operator<( const Fixed &fixed ) const;
	bool	operator>=( const Fixed &fixed ) const;
	bool	operator<=( const Fixed &fixed ) const;
	bool	operator==( const Fixed &fixed ) const;
	bool	operator!=( const Fixed &fixed ) const;
	Fixed	operator+( const Fixed &fixed ) const;
	Fixed	operator-( const Fixed &fixed ) const;
	Fixed	operator*( const Fixed &fixed ) const;
	Fixed	operator/( const Fixed &fixed ) const;
	Fixed&	operator++( void );	// 전위 연산자 ++a
	Fixed&	operator--( void );	// 전위 연산자 --a
	Fixed	operator++( int );	// 후위 연산자 a++
	Fixed	operator--( int );	// 후위 연산자 a--
	
	int	getRawBits(void) const;
	void setRawBits(int const raw);
	int getRawBits(void) const;
	float toFloat(void) const;
	int toInt(void) const;
	private:
	int fixedPoint;
	static const int fractionalBits = 8;
};

std::ostream& operator<<(std::ostream& out, const Fixed& src);
#endif