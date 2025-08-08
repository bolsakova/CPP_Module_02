#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed {

	private:
			int					_fixedPointValue;					// integer to keep
			static const int	_fractionalBits = 8;	// always 8 bits for fractional part

	public:
			// Constructors and destructor
			Fixed();								// Default constructor - initialized value with 0
			Fixed(int const _intValue);				// Constructor with parameter (int) - converts a constant integer to the corresponding fixed-point value
			Fixed(float const _floatValue);			// Constructor with parameter (float) - converts a constant floating-point number to the corresponding fixed-point value
			Fixed(const Fixed& other);				// Copy constructor - copy the object (always constant reference)
			Fixed&	operator=(const Fixed& other);	// Assignment operator - assigning (1) copy the data from one already existing object to another one (2) is called when c = b; (с is already created)
			~Fixed();								// Destructor - destroys the object, frees resources (memory, sockets, files etc.)
			
			// Methods
			float	toFloat( void ) const;			// member function converts the fixed-point value to a floating-point value
			int		toInt( void ) const;			// member function converts the fixed-point value to an int value

			// Overload of comparison operators
			bool	operator>(const Fixed& other) const;
			bool	operator<(const Fixed& other) const;
			bool	operator>=(const Fixed& other) const;
			bool	operator<=(const Fixed& other) const;
			bool	operator==(const Fixed& other) const;
			bool	operator!=(const Fixed& other) const;

			// Overload of arithmetic operators
			Fixed	operator+(const Fixed& other) const;
			Fixed	operator-(const Fixed& other) const;
			Fixed	operator*(const Fixed& other) const;
			Fixed	operator/(const Fixed& other) const;

			// Overload of increment/decrement operators
			// prefix
			Fixed&	operator++();
			Fixed&	operator--();
			// postfix
			Fixed	operator++(int);
			Fixed	operator--(int);

			// 

};
// Overload of the insertion (<<)
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
