/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torinoue <torinoue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:18 by torinoue          #+#    #+#             */
/*   Updated: 2025/08/15 16:36:35 by torinoue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AnsiColor.hpp"
#include "Fixed.hpp"
#include <climits>
#include <cmath>

const int Fixed::_fractionalBits = 8;

// std::cerr << ANSI_COLOR_YELLOW << "Fixed Default Constructor called" << ANSI_COLOR_RESET << std::endl;
Fixed::Fixed() : _value(0){
}

// std::cerr << ANSI_COLOR_YELLOW << "Fixed Copy Constructor called" << ANSI_COLOR_RESET << std::endl;
Fixed::Fixed(const Fixed & src){

	*this = src;
}

// std::cerr << ANSI_COLOR_YELLOW << "Fixed Integer Constructor called" << ANSI_COLOR_RESET << std::endl;
Fixed::Fixed(const int integer): _value(integer << _fractionalBits){

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

// std::cerr << ANSI_COLOR_YELLOW << "Fixed Float Constructor called" << ANSI_COLOR_RESET << std::endl;
// std::cerr << ANSI_COLOR_YELLOW << "			floatingPointNumber=" << floatingPointNumber << ANSI_COLOR_RESET << std::endl;
Fixed::Fixed(const float floatingPointNumber){
	const float MIN_REPRESENTABLE = 1.0f / (1 << _fractionalBits);
	const float BOUNDARY = MIN_REPRESENTABLE / 2.0f;

	float abs_input = (floatingPointNumber < 0.0f) ? -floatingPointNumber : floatingPointNumber;

	if (floatingPointNumber != 0.0f && abs_input < MIN_REPRESENTABLE) {

		std::cerr << ANSI_COLOR_YELLOW << "Warning: Input value " << floatingPointNumber 
				  << " (absolute value " << abs_input << ") is smaller than minimum representable value " 
				  << MIN_REPRESENTABLE << " (1/" << (1 << _fractionalBits) << ")." << std::endl;

		if (abs_input < BOUNDARY) {
			std::cerr << "         Since |" << floatingPointNumber << "| < " << BOUNDARY 
					  << " (boundary = " << MIN_REPRESENTABLE << " / 2   exact value unaffected by std::cout is 0.001953125), \n          value will be rounded to 0." << ANSI_COLOR_RESET << std::endl;
		} else {
			std::cerr << "         Since |" << floatingPointNumber << "| >= " << BOUNDARY 
					  << " (boundary = " << MIN_REPRESENTABLE << " / 2   exact value unaffected by std::cout is 0.001953125),\n          value will be rounded to " 
					  << MIN_REPRESENTABLE << " (getRawBits = 1)." << ANSI_COLOR_RESET << std::endl;
		}
	}

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

// std::cerr << ANSI_COLOR_RED << "Fixed Destructor called" << ANSI_COLOR_RESET << std::endl;
Fixed::~Fixed(){
}

// std::cout << ANSI_COLOR_BLUE << "getRawBits member function called" << ANSI_COLOR_RESET << std::endl;
int Fixed::getRawBits( void ) const{
	return (this->_value);
}

// std::cout << "setRawBits member function called" << std::endl;
void Fixed::setRawBits( int const raw ){
	this->_value = raw;
}

/* Static member functions */
Fixed &Fixed::min(Fixed &a, Fixed &b){
	return (a._value > b._value ? b : a);
}
Fixed &Fixed::max(Fixed &a, Fixed &b){
	return (a._value < b._value ? b : a);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b){
	return (a._value > b._value ? b : a);
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b){
	return (a._value < b._value ? b : a);
}

// std::cout << ANSI_COLOR_YELLOW << "Fixed Copy Assignment Operator called" << ANSI_COLOR_RESET << std::endl;
Fixed &Fixed::operator =(const Fixed &src){
	if (this != &src)
	{
		this->_value = src.getRawBits();
	}
	return *this;
}

float	Fixed::toFloat(void) const{
	return (static_cast<float>(this->_value) / (1 << _fractionalBits));
}

int		Fixed::toInt(void) const{
	return (this->_value >> _fractionalBits);
}

/* The 6 comparison operators: >, <, >=, <=, ==, and !=. */
bool	Fixed::operator >(const Fixed &other) const{
	return (this->_value > other._value);
}

bool	Fixed::operator <(const Fixed &other) const{
	return (this->_value < other._value);
}

bool	Fixed::operator >=(const Fixed &other) const{
	return (this->_value >= other._value);
}

bool	Fixed::operator <=(const Fixed &other) const{
	return (this->_value <= other._value);
}

bool	Fixed::operator ==(const Fixed &other) const{
	return (this->_value == other._value);
}

bool	Fixed::operator !=(const Fixed &other) const{
	return (this->_value != other._value);
}

/* The 4 arithmetic operators: +, -, *, and /. */
Fixed	Fixed::operator +(const Fixed &other) const{
	long long result = static_cast<long long>(this->_value) + static_cast<long long>(other._value);

	if (result > INT_MAX) {
		std::cerr << ANSI_COLOR_RED << "Warning: Addition result " << result 
				  << " exceeds INT_MAX (" << INT_MAX << "). Overflow occurred! Result clamped to INT_MAX." << ANSI_COLOR_RESET << std::endl;
		result = INT_MAX;
	}
	else if (result < INT_MIN) {
		std::cerr << ANSI_COLOR_RED << "Warning: Addition result " << result 
				  << " is below INT_MIN (" << INT_MIN << "). Underflow occurred! Result clamped to INT_MIN." << ANSI_COLOR_RESET << std::endl;
		result = INT_MIN;
	}

	Fixed resultFixed;
	resultFixed.setRawBits(static_cast<int>(result));
	return resultFixed;
}

Fixed	Fixed::operator -(const Fixed &other) const{
	long long result = static_cast<long long>(this->_value) - static_cast<long long>(other._value);

	if (result > INT_MAX) {
		std::cerr << ANSI_COLOR_RED << "Warning: Subtraction result " << result 
				  << " exceeds INT_MAX (" << INT_MAX << "). Overflow occurred! Result clamped to INT_MAX." << ANSI_COLOR_RESET << std::endl;
		result = INT_MAX;
	}
	else if (result < INT_MIN) {
		std::cerr << ANSI_COLOR_RED << "Warning: Subtraction result " << result 
				  << " is below INT_MIN (" << INT_MIN << "). Underflow occurred! Result clamped to INT_MIN." << ANSI_COLOR_RESET << std::endl;
		result = INT_MIN;
	}

	Fixed resultFixed;
	resultFixed.setRawBits(static_cast<int>(result));
	return resultFixed;
}

Fixed	Fixed::operator *(const Fixed &other) const{
	long long result = static_cast<long long>(this->_value) * static_cast<long long>(other._value);
	result >>= _fractionalBits;

	if (result > INT_MAX) {
		std::cerr << ANSI_COLOR_RED << "Warning: Multiplication result " << result 
				  << " exceeds INT_MAX (" << INT_MAX << "). Overflow occurred! Result clamped to INT_MAX." << ANSI_COLOR_RESET << std::endl;
		result = INT_MAX;
	}
	else if (result < INT_MIN) {
		std::cerr << ANSI_COLOR_RED << "Warning: Multiplication result " << result 
				  << " is below INT_MIN (" << INT_MIN << "). Underflow occurred! Result clamped to INT_MIN." << ANSI_COLOR_RESET << std::endl;
		result = INT_MIN;
	}

	Fixed resultFixed;
	resultFixed.setRawBits(static_cast<int>(result));
	return resultFixed;
}

Fixed	Fixed::operator /(const Fixed &other) const{
	if (other._value == 0) {
		std::cerr << ANSI_COLOR_RED << "Error: Division by zero!" << ANSI_COLOR_RESET << std::endl;
		int dummy = 1 / other.getRawBits();
		return Fixed(dummy);
	}

	if (other._value == (1 << _fractionalBits)) {
		Fixed result;
		result.setRawBits(this->_value);
		return result;
	}

	long long extended_dividend = static_cast<long long>(this->_value) << _fractionalBits;
	long long raw_quotient = extended_dividend / static_cast<long long>(other._value);

	long long remainder = extended_dividend % static_cast<long long>(other._value);
	if (remainder != 0) {
		bool dividend_positive = (extended_dividend >= 0);
		bool divisor_positive = (other._value >= 0);
		bool same_sign = (dividend_positive == divisor_positive);

		long long abs_remainder = (remainder < 0) ? -remainder : remainder;
		long long abs_divisor = (other._value < 0) ? -static_cast<long long>(other._value) : static_cast<long long>(other._value);

		if (abs_remainder * 2 >= abs_divisor) {
			raw_quotient += same_sign ? 1 : -1;
		}
	}

	if (raw_quotient > static_cast<long long>(INT_MAX)) {
		std::cerr << ANSI_COLOR_RED << "Warning: Division result " << raw_quotient 
				  << " exceeds maximum representable value (" << INT_MAX 
				  << "). Result clamped to maximum." << ANSI_COLOR_RESET << std::endl;
		raw_quotient = static_cast<long long>(INT_MAX);
	}
	else if (raw_quotient < static_cast<long long>(INT_MIN)) {
		std::cerr << ANSI_COLOR_RED << "Warning: Division result " << raw_quotient 
				  << " is below minimum representable value (" << INT_MIN 
				  << "). Result clamped to minimum." << ANSI_COLOR_RESET << std::endl;
		raw_quotient = static_cast<long long>(INT_MIN);
	}

	Fixed result;
	result.setRawBits(static_cast<int>(raw_quotient));
	return result;
}


/* The 4 increment/decrement (pre-increment and post-increment, pre-decrement and
post-decrement) operators, which will increase or decrease the fixed-point value by
the smallest representable ϵ, such that 1 + ϵ > 1. */

// std::cout << ANSI_COLOR_YELLOW << "Fixed Pre-Increment Operator called" << ANSI_COLOR_RESET << std::endl;
Fixed	&Fixed::operator ++(void){
	this->_value++;
	return (*this);
}

// std::cout << ANSI_COLOR_YELLOW << "Fixed Post-Increment Operator called" << ANSI_COLOR_RESET << std::endl;
Fixed	Fixed::operator ++(int){
	Fixed temp(*this);
	this->_value++;
	return (temp);
}

// std::cout << ANSI_COLOR_YELLOW << "Fixed Pre-Decrement Operator called" << ANSI_COLOR_RESET << std::endl;
Fixed	&Fixed::operator --(void){
	this->_value--;
	return (*this);
}

// std::cout << ANSI_COLOR_YELLOW << "Fixed Post-Decrement Operator called" << ANSI_COLOR_RESET << std::endl;
Fixed	Fixed::operator --(int){
	Fixed temp(*this);
	this->_value--;
	return (temp);
}

std::ostream &operator <<(std::ostream &outputStream, const Fixed &fixed){
	return(outputStream << fixed.toFloat());
}
