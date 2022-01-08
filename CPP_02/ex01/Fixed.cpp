#include "Fixed.hpp"

Fixed::Fixed() : fixedPoint(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(float const floatVal)
{
	std::cout << "Float Constructor called" << std::endl;
	// bisa라고 하는 지정된 수자를 더한 다음 넣어야한다.
	this->fixedPoint = (int)roundf(floatVal * (1 << fractionalBits));
	
}

Fixed::Fixed(int const intVal)
{
	std::cout << "Int Constructor called" << std::endl;
	this->fixedPoint = intVal << fractionalBits;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const Fixed &fixed )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed&	Fixed::operator=( const Fixed &fixed )
{
	std::cout << "Assignation operator called" << std::endl;
	this->fixedPoint = fixed.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	return (this->fixedPoint);
}

void Fixed::setRawBits(int const raw)
{
	this->fixedPoint = raw;
}

float Fixed::toFloat(void) const
{
	return (this->fixedPoint / (float)(1 << fractionalBits));
}

int Fixed::toInt(void) const
{
	return (this->fixedPoint >> fractionalBits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& src)
{
	out << src.toFloat();
	return (out);
}