#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(int const _intValue) {
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = _intValue << _fractionalBits; // shift on 8 bits (or * 2^8 = * 256)
}

// конструктор преобразует число с плавающей запятой в фиксированное значение
Fixed::Fixed(float const _floatValue) {
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(_floatValue * (1 << _fractionalBits)); // сдвиг на 8 бит (или * 2^8 = * 256)
}

// создаем новый объект как точную копю существующего объекта
//		Fixed a; - default constructor
//		Fixed b(a); - copy constructor (создаем b как копию a)
//		Fixed c = a; - copy constructor (НЕ assignment, т.к. с еще не существует)
// без & - будет вызван copy constructor для параметра (доп. копирование) => бесконечная рекурсия
Fixed::Fixed(const Fixed& other) : _fixedPointValue(other._fixedPointValue) {
	std::cout << "Copy constructor called" << std::endl;
};

// копируем данные из одного уже существующего объекта в другой уже существующий объект
//		Fixed a; - default constructor
//		Fixed b; - default constructor
//		Fixed c = a; - assignment operator (копируем a в b, оба уже существуют)
Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	// проверка на самоприсваивание
	if (this != &other) {
		// копируем данные
		this->_fixedPointValue = other._fixedPointValue;
	}
	// возврат ссылки на текущий объект
	return *this;
};

// в С++ если мы не напишем деструктор, компилятор создаст его автоматически
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
