#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed {
private:
	// целое число для хранения
	int _fixedPointValue;
	// всегда 8 бит под дробную часть
	static const int _fractionalBits = 8;
public:
	// Default constructor - инициализирует значение в 0
	Fixed();
	// Copy constructor - копирует объект (обязательно константная ссылка)
	//		const - мы не изменяем исходный объект
	//		& - избегаем лишнего копирования (передача по ссылке)
	Fixed(const Fixed& other);
	// Assignment operator - присваивание
	//		- копирует данные из одного уже существующего объекта в другой уже существующий
	//		- вызывается при c = b; (когда с уже создан)
	//		Fixed& - возвращаем ссылку на текущий объект (для цепочек a=b=c)
	//		operator= - ключевое слово для перегрузки оператора присваивания
	Fixed& operator=(const Fixed& other);
	// Destructor - уничтожает объект, освобождает ресурсы (память, сокеты, файлы и т.д.)
	~Fixed();
	// геттер - возвращает "сырое" внутренне представление
	//		возвращает 384 в двоичном виде (не 1.5)
	int getRawBits(void) const;
	// сеттер - устанавливает "сырое" внутреннее представление
	//		сохраняет 384 в двоичном виде (не 1.5)
	void setRawBits(int const raw);
};

#endif
