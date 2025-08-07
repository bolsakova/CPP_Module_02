#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed {

	private:
			int _fixedPointValue;					// целое число для хранения
			static const int _fractionalBits = 8;	// всегда 8 бит под дробную часть

	public:
			
			Fixed();								// Default constructor - initialized value with 0
			Fixed(int const _intValue);				// Constructor with parameter (int) - converts a constant integer to the corresponding fixed-point value
			Fixed(float const _floatValue);			// Constructor with parameter (float) - converts a constant floating-point number to the corresponding fixed-point value
			Fixed(const Fixed& other);				// Copy constructor - copy the object (always constant reference)
			Fixed&	operator=(const Fixed& other);	// Assignment operator - assigning (1) copy the data from one already existing object to another one (2) is called when c = b; (с is already created)
			~Fixed();								// Destructor - destroys the object, frees resources (memory, sockets, files etc.)
			
			float	toFloat( void ) const;			// member function converts the fixed-point value to a floating-point value
			int		toInt( void ) const;			// member function converts the fixed-point value to an int value
};

#endif
