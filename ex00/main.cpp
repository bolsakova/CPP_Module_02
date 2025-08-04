#include "Fixed.hpp"

int main() {
	Fixed a;	// Default constructor
	Fixed b(a);	// Copy constructor
	Fixed c;	// Default constructor

	c = b;		// Assignment operator

	// a.setRawBits(42);
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
}
