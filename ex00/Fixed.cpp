#include "Fixed.hpp"

// Default constructor with initializing value 0 to the object we create
Fixed::Fixed() : _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
};

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
	if (this != &other)
		this->_fixedPointValue = other._fixedPointValue;
	return *this;
};

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
};

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointValue;
};

void Fixed::setRawBits(int const raw) {
	this->_fixedPointValue = raw;
};
