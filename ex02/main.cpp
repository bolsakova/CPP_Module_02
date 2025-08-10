#include "Fixed.hpp"

int main() {
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	Fixed c;
	Fixed const d(Fixed(4.5f) * Fixed(2));

	std::cout << "\n=== Assignment ===" << std::endl;
	a = Fixed(15);
	c = Fixed(10);
	std::cout << "Assigned a = " << a << std::endl;
	std::cout << "Assigned c = " << c << std::endl;

	std::cout << "\n=== Comparison Operators ===" << std::endl;
	std::cout << "a > c is " << (a > c) << std::endl;
	std::cout << "a < c is " << (a < c) << std::endl;
	std::cout << "a >= c is " << (a >= c) << std::endl;
	std::cout << "a <= c is " << (a <= c) << std::endl;
	std::cout << "a == c is " << (a == c) << std::endl;
	std::cout << "a != c is " << (a != c) << std::endl;

	std::cout << "\n=== Arithmetic Operators ===" << std::endl;
	std::cout << "a + c = " << (a + c) << std::endl;
	std::cout << "a - c = " << (a - c) << std::endl;
	std::cout << "a * c = " << (a * c) << std::endl;
	std::cout << "a / c = " << (a / c) << std::endl;

	std::cout << "\n=== Increment/Decrement ===" << std::endl;
	a = Fixed();
	std::cout << "Start value -> a is " << a << std::endl;
	std::cout << "Prefix increment -> ++a is " << ++a << std::endl;
	std::cout << "After prefix increment -> a is " << a << std::endl;
	std::cout << "Doing postfix increment -> a++ is " << a++ << std::endl;
	std::cout << "After postfix increment -> a is " << a << std::endl;

	std::cout << "\n=== Non-Const Min/Max ===" << std::endl;
	std::cout << "Before: a = " << a << ", c = " << c << std::endl;
	Fixed& minRef = Fixed::min(a, c);
	Fixed& maxRef = Fixed::max(a, c);
	std::cout << "Non-const Min(a, c): " << minRef << std::endl;
	std::cout << "Non-const Max(a, c): " << maxRef << std::endl;
	minRef = Fixed(0);
	maxRef = Fixed(1);
	std::cout << "After modifying minRef and maxRef: a = " << a << ", c = " << c << std::endl;

	std::cout << "\n=== Const Min/Max ===" << std::endl;
	std::cout << "Const b = " << b << ", Const d = " << d << std::endl;
	std::cout << "Const Min(b, d): " << Fixed::min(b, d) << std::endl;
	std::cout << "Const Max(b, d): " << Fixed::max(b, d) << std::endl;

	return 0;
}
