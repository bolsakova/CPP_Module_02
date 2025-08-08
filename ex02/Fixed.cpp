#include "Fixed.hpp"

/**
 * CONSTRUCTORS:
 */
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

Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other)
		this->_fixedPointValue = other._fixedPointValue;
	return *this;
};

Fixed::~Fixed() {
};

/**
 * METHODS:
 */
float	Fixed::toFloat( void ) const {
	return (float)this->_fixedPointValue / (1 << _fractionalBits);
}

int		Fixed::toInt( void ) const {
	return this->_fixedPointValue >> _fractionalBits;
}

// (function)
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;
}
