#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0)
{
}

Fixed::Fixed(const int value)
{
	this->_rawBits = value << this->_fractionalBits;
}

Fixed::Fixed(const float value)
{
	this->_rawBits = roundf(value * (1 << this->_fractionalBits));
}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->_rawBits = other.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
}

int	Fixed::getRawBits(void) const
{
	return (this->_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_rawBits / (1 << this->_fractionalBits));
}

int	Fixed::toInt(void) const
{
	return (this->_rawBits >> this->_fractionalBits);
}

bool	Fixed::operator>(const Fixed& other) const
{
	return (this->_rawBits > other._rawBits);
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (this->_rawBits < other._rawBits);
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (this->_rawBits >= other._rawBits);
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (this->_rawBits <= other._rawBits);
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (this->_rawBits == other._rawBits);
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (this->_rawBits != other._rawBits);
}

Fixed	Fixed::operator+(const Fixed& other) const
{
	Fixed	result;
	result.setRawBits(this->_rawBits + other._rawBits);
	return (result);
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	Fixed	result;
	result.setRawBits(this->_rawBits - other._rawBits);
	return (result);
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	Fixed	result;
	result.setRawBits((this->_rawBits * other._rawBits) >> this->_fractionalBits);
	return (result);
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	Fixed	result;
	result.setRawBits((this->_rawBits << this->_fractionalBits) / other._rawBits);
	return (result);
}

Fixed&	Fixed::operator++(void)
{
	this->_rawBits++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);
	this->_rawBits++;
	return (temp);
}

Fixed&	Fixed::operator--(void)
{
	this->_rawBits--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);
	this->_rawBits--;
	return (temp);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b ? a : b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b ? a : b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b ? a : b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b ? a : b);
}

std::ostream&	operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}
