#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed {
private:
	// целое число для хранения
	int _fixedPointValue;
	// всегда 8 бит под дробную часть
	static const int _fractionalBits = 8;
public:
	// Default constructor - инициализирует значение в 0
	Fixed() : _fixedPointValue(0);
	// Copy constructor - копирует объект
	// Assignment operator - присваивание
	// Destructor - уничтожает объект
	// возвращает "сырое" значение
	getRawBits();
	// устанавливает "сырое" значение
	setRawBits();
};

#endif
