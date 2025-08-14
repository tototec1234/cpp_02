/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:18 by torinoue          #+#    #+#             */
/*   Updated: 2025/08/14 15:30:31 by toruinoue        ###   ########.fr       */
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
	
	const int MAX_SAFE_INT = INT_MAX / (1 << _fractionalBits);
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


Fixed::Fixed(const float floatingPointNumber)
{
	std::cerr << ANSI_COLOR_YELLOW << "Fixed Float Constructor called" << ANSI_COLOR_RESET << std::endl;
	// std::cerr << ANSI_COLOR_YELLOW << "			floatingPointNumber=" << floatingPointNumber << ANSI_COLOR_RESET << std::endl;
	
	long long scaled_result = static_cast<long long>(roundf(floatingPointNumber * (1 << _fractionalBits)));
		
	if (scaled_result > INT_MAX) {
		std::cerr << ANSI_COLOR_RED << "		Warning: Rounded result " << scaled_result 
				  << " exceeds INT_MAX (" << INT_MAX << "). Overflow occurred!" << ANSI_COLOR_RESET << std::endl;
		_value = static_cast<int>(scaled_result);
	}
	else if (scaled_result < INT_MIN) {
		std::cerr << ANSI_COLOR_RED << "		Warning: Rounded result " << scaled_result 
				  << " is below INT_MIN (" << INT_MIN << "). Underflow occurred!" << ANSI_COLOR_RESET << std::endl;
		_value = static_cast<int>(scaled_result);
	}
	else {
		_value = static_cast<int>(scaled_result);
	}
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

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Fixed Copy Assignment Operator called" << std::endl;
	if (this != &src)
	{
		this->_value = src.getRawBits();
	}
	return *this;
}

// float	Fixed::toFloat(void) 
float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_value) / (1 << _fractionalBits));
}

int		Fixed::toInt(void) const
{
	return (this->_value >> _fractionalBits);
}

std::ostream &operator<<(std::ostream &outputStream, const Fixed &fixed)
{
	return(outputStream << fixed.toFloat());
}

