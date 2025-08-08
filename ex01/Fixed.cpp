#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
};

// (constructor) integer -> fixed-point
Fixed::Fixed(int const _intValue) {
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = _intValue << _fractionalBits;
}

// (constructor) floating-point -> fixed-point
Fixed::Fixed(float const _floatValue) {
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(_floatValue * (1 << _fractionalBits));
}

// (copy constructor) create a new object as an exact copy of an existing object
//		Fixed b(a); - copy constructor (create b as copy of a)
//		Fixed c = a; - copy constructor (NOT assignment because c doesn't exist)
// !!! without & - will be called copy constructor for parameter (additional copy) => infinite recursion
Fixed::Fixed(const Fixed& other) : _fixedPointValue(other._fixedPointValue) {
	std::cout << "Copy constructor called" << std::endl;
};

// (assignment operator) copy data from one existing object to another existing object
//		Fixed c = a; - assignment operator (copy a to c, both exist)
Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	// self-assignment check
	if (this != &other) {
		// copying data
		this->_fixedPointValue = other._fixedPointValue;
	}
	// return pointer to the current object
	return *this;
};

// destructor
// in C++ if we don't create the destructor, compilor will create it automatically
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
};

// (function) fixed-point -> floating-point
float	Fixed::toFloat( void ) const {
	// divide by 256.0f
	return (float)this->_fixedPointValue / (1 << _fractionalBits);
}

// (function) fixed-point -> int
int		Fixed::toInt( void ) const {
	// shift on 8 bits to the right (divide by 256 (2^8))
	return this->_fixedPointValue >> _fractionalBits;
}

// (function)
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat(); // getting the value
	return out;
}
