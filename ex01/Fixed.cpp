#include "Fixed.hpp"

// создаем объект сразу со значением 0
Fixed::Fixed() : _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
};

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
