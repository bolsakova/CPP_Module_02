#include "Fixed.hpp"

// constructors
Fixed::Fixed() : _fixedPointValue(0) {
};

Fixed::Fixed(int const _intValue) {
	this->_fixedPointValue = _intValue << _fractionalBits;
}

Fixed::Fixed(float const _floatValue) {
	this->_fixedPointValue = roundf(_floatValue * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other) : _fixedPointValue(other._fixedPointValue) {
};

// destructor
Fixed::~Fixed() {
};

// fixed-point -> floating-point
float	Fixed::toFloat( void ) const {
	return (float)this->_fixedPointValue / (1 << _fractionalBits);
}

// fixed-point -> integer
int		Fixed::toInt( void ) const {
	return this->_fixedPointValue >> _fractionalBits;
}

// function to overload assignment operator
Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other)
		this->_fixedPointValue = other._fixedPointValue;
	return *this;
};

// function to overload insertion
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;
}

// functions to overload comparison operators
bool	Fixed::operator>(const Fixed& other) const {

}

bool	Fixed::operator<(const Fixed& other) const {

}

bool	Fixed::operator>=(const Fixed& other) const {

}

bool	Fixed::operator<=(const Fixed& other) const {

}

bool	Fixed::operator==(const Fixed& other) const {

}

bool	Fixed::operator!=(const Fixed& other) const {
	
}


// functions to overload arithmetic operators
Fixed	Fixed::operator+(const Fixed& other) const {

}

Fixed	Fixed::operator-(const Fixed& other) const {

}

Fixed	Fixed::operator*(const Fixed& other) const {

}

Fixed	Fixed::operator/(const Fixed& other) const {

}

// functions to overload increment/decrement operators
// prefix
Fixed&	Fixed::operator++() {

}

Fixed&	Fixed::operator--() {

}

// postfix
Fixed	Fixed::operator++(int) {

}

Fixed	Fixed::operator--(int) {

}

// static overloaded functions min/max
// min
Fixed&			Fixed::min(Fixed& a, Fixed& b) {

}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) {

}

// max
Fixed&			Fixed::max(Fixed& a, Fixed& b) {

}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) {

}

