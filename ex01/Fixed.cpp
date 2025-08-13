/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:18 by torinoue          #+#    #+#             */
/*   Updated: 2025/08/13 20:56:59 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AnsiColor.hpp"
#include "Fixed.hpp"
#include <iomanip>
#include <climits>

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _value(0)
{
    std::cerr << ANSI_COLOR_YELLOW << "Fixed Default Constructor called" << ANSI_COLOR_RESET << std::endl;
}

Fixed::Fixed(const Fixed & src)
{
    std::cerr << ANSI_COLOR_YELLOW << "Fixed Copy Constructor called" << ANSI_COLOR_RESET << std::endl;
    *this = src;
}

Fixed::Fixed(const int integer): _value(integer << _fractionalBits)
{
	std::cerr << ANSI_COLOR_YELLOW << "Fixed Integer Constructor called" << ANSI_COLOR_RESET << std::endl;
	
	// 上限値チェック（INT_MAX / 256 = 8388607）
	const int MAX_SAFE_INT = INT_MAX / (1 << _fractionalBits);
	// 下限値チェック（INT_MIN / 256 = -8388608）
	const int MIN_SAFE_INT = INT_MIN / (1 << _fractionalBits);

	
	if (integer > MAX_SAFE_INT) {
		std::cerr << ANSI_COLOR_RED << "Warning: Integer " << integer 
				  << " exceeds maximum safe value " << MAX_SAFE_INT 
				  << ". Overflow occurred!" << ANSI_COLOR_RESET << std::endl;
	}
	else if (integer < MIN_SAFE_INT) {
		std::cerr << ANSI_COLOR_RED << "Warning: Integer " << integer 
				  << " is below minimum safe value " << MIN_SAFE_INT 
				  << ". Underflow occurred!" << ANSI_COLOR_RESET << std::endl;
	}
}


// Fixed::Fixed(const float floatingPointNumber): _value(static_cast<int>(roundf( floatingPointNumber * pow(2, _fractionalBits))))
Fixed::Fixed(const float floatingPointNumber): _value(static_cast<int>(roundf(floatingPointNumber * (1 << _fractionalBits))))
{
	std::cerr << ANSI_COLOR_YELLOW << "Fixed Float Constructor called" << ANSI_COLOR_RESET << std::endl;
	std::cerr << ANSI_COLOR_YELLOW << "			floatingPointNumber=" << floatingPointNumber << ANSI_COLOR_RESET << std::endl;
	
	// 事前範囲チェック（オーバーフロー前に判定）
	const float MAX_SAFE_FLOAT = static_cast<float>(INT_MAX) / (1 << _fractionalBits);
	const float MIN_SAFE_FLOAT = static_cast<float>(INT_MIN) / (1 << _fractionalBits);
	
	std::cerr << ANSI_COLOR_YELLOW << "----MAX_SAFE_FLOAT=" << MAX_SAFE_FLOAT << ANSI_COLOR_RESET << std::endl;
	// std::cerr << ANSI_COLOR_YELLOW << "----MIN_SAFE_FLOAT=" << MIN_SAFE_FLOAT << ANSI_COLOR_RESET << std::endl;
	// INT_MAX/MIN チェック（事前）
	if (floatingPointNumber > MAX_SAFE_FLOAT) {
		std::cerr << ANSI_COLOR_RED << "		Warning: Float " << floatingPointNumber 
				  << " exceeds maximum safe value " << MAX_SAFE_FLOAT
				  << ". Overflow will occur!" << ANSI_COLOR_RESET << std::endl;
	}
	else if (floatingPointNumber < MIN_SAFE_FLOAT) {
		std::cerr << ANSI_COLOR_RED << "		Warning: Float " << floatingPointNumber 
				  << " is below minimum safe value " << MIN_SAFE_FLOAT
				  << ". Underflow will occur!" << ANSI_COLOR_RESET << std::endl;
	}
	float scaled_value = floatingPointNumber * (1 << _fractionalBits);
	int int_scaled_value = static_cast<int>(scaled_value);
	std::cerr << ANSI_COLOR_BLUE << "			scaled_value=" << scaled_value << ANSI_COLOR_RESET << std::endl;
	std::cerr << ANSI_COLOR_BLUE << "			int_scaled_value=" << int_scaled_value << ANSI_COLOR_RESET << std::endl;
}
		
Fixed::~Fixed()
{
    std::cerr << ANSI_COLOR_RED << "Fixed Destructor called" << ANSI_COLOR_RESET << std::endl;
}


int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

Fixed &Fixed::operator=(const Fixed &src) {
	std::cout << "Fixed Copy Assignment Operator called" << std::endl;
	if (this != &src) {
		this->_value = src.getRawBits();
	}
	return *this;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_value) / (1 << _fractionalBits));
}

int		Fixed::toInt(void) const
{
	return (this->_value >> _fractionalBits);
}

std::ostream &operator<<(std::ostream &str, const Fixed &fixed)
{
	return(str << fixed.toFloat());
}

/*
float	Fixed::toFloat(void) const
{
	
	std::cerr << ANSI_COLOR_BLUE << "  _value=" << this->_value << ANSI_COLOR_RESET << std::endl;
	std::cerr << ANSI_COLOR_BLUE << "  static_cast<float>(this->_value)=" << static_cast<float>(this->_value) << ANSI_COLOR_RESET << std::endl;
	// 両方の実装を計算
	float method1 = (this->_value) / (1 << _fractionalBits);
	float method2 = static_cast<float>(this->_value) / (1 << _fractionalBits);
	
	// 結果を出力して比較
	std::cerr << ANSI_COLOR_BLUE << "  _value=" << this->_value 
			  << " method1=" << std::fixed << std::setprecision(10) << method1
			  << " method2=" << method2 
			  << " diff=" << (method1 - method2) << ANSI_COLOR_RESET << std::endl;
	
	// 現在使用している実装を返す
	return method2;
}
*/