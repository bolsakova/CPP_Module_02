#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed {

	private:
			int _fixedPointValue;					// integer to keep
			static const int _fractionalBits = 8;	// always 8 bits for fractional part

	public:
			
			Fixed();								// Default constructor - initialized value with 0
			Fixed(const Fixed& other);				// Copy constructor - copy the object (always constant reference)
			Fixed&	operator=(const Fixed& other);	// Assignment operator - assigning (1) copy the data from one already existing object to another one (2) is called when c = b; (с is already created)
			~Fixed();								// Destructor - destroys the object, frees resources (memory, sockets, files etc.)
			
			
			int getRawBits(void) const;				// getter - returns "raw" fixed-point representation
			void setRawBits(int const raw);			// setter - sets "raw" fixed-point representation
};

#endif
