/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:18 by torinoue          #+#    #+#             */
/*   Updated: 2025/08/14 20:13:04 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AnsiColor.hpp"
#include "Fixed.hpp"
#include <iomanip>
#include <climits>

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _value(0){
    // std::cerr << ANSI_COLOR_YELLOW << "Fixed Default Constructor called" << ANSI_COLOR_RESET << std::endl;
}

Fixed::Fixed(const Fixed & src){
    // std::cerr << ANSI_COLOR_YELLOW << "Fixed Copy Constructor called" << ANSI_COLOR_RESET << std::endl;
    *this = src;
}

Fixed::Fixed(const int integer): _value(integer << _fractionalBits){
	// std::cerr << ANSI_COLOR_YELLOW << "Fixed Integer Constructor called" << ANSI_COLOR_RESET << std::endl;
	
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


Fixed::Fixed(const float floatingPointNumber){
	// std::cerr << ANSI_COLOR_YELLOW << "Fixed Float Constructor called" << ANSI_COLOR_RESET << std::endl;
	// std::cerr << ANSI_COLOR_YELLOW << "			floatingPointNumber=" << floatingPointNumber << ANSI_COLOR_RESET << std::endl;
	
	long long scaled_result = static_cast<long long>(roundf(floatingPointNumber * (1 << _fractionalBits)));
	
	// std::cerr << ANSI_COLOR_BLUE << "			scaled_result (long long)=" << scaled_result << ANSI_COLOR_RESET << std::endl;
	
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
	
	// if (scaled_result > 0) {
	// 	std::cerr << ANSI_COLOR_BLUE << "			Difference from INT_MAX  =" << INT_MAX - scaled_result << std::endl;
	// } else {
	// 	std::cerr << ANSI_COLOR_BLUE << "			Difference from INT_MIN  =" << scaled_result - INT_MIN << std::endl;
	// }	
	// std::cerr << ANSI_COLOR_BLUE << "			final _value=" << _value << ANSI_COLOR_RESET << std::endl;

}
		
Fixed::~Fixed(){
    // std::cerr << ANSI_COLOR_RED << "Fixed Destructor called" << ANSI_COLOR_RESET << std::endl;
}


int Fixed::getRawBits( void ) const{
	// std::cout << ANSI_COLOR_BLUE << "getRawBits member function called" << ANSI_COLOR_RESET << std::endl;
	return (this->_value);
}

void Fixed::setRawBits( int const raw ){
	// std::cout << "setRawBits member function called" << std::endl;
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

// Overloaded Operators
	/* Assignment operator */
Fixed &Fixed::operator =(const Fixed &src){
	// std::cout << ANSI_COLOR_YELLOW << "Fixed Copy Assignment Operator called" << ANSI_COLOR_RESET << std::endl;
	if (this != &src)
	{
		this->_value = src.getRawBits();
	}
	return *this;
}

// float	Fixed::toFloat(void) 
float	Fixed::toFloat(void) const{
	return (static_cast<float>(this->_value) / (1 << _fractionalBits));
}

int		Fixed::toInt(void) const{
	return (this->_value >> _fractionalBits);
}

/* The 6 comparison operators: >, <, >=, <=, ==, and !=. */
bool	Fixed::operator >(const Fixed &other) const{
	return (this->toFloat() > other.toFloat());
}

bool	Fixed::operator <(const Fixed &other) const{
	return (this->toFloat() < other.toFloat());
}

bool	Fixed::operator >=(const Fixed &other) const{
	return (this->toFloat() >= other.toFloat());
}

bool	Fixed::operator <=(const Fixed &other) const{
	return (this->toFloat() <= other.toFloat());
}

bool	Fixed::operator ==(const Fixed &other) const{
	return (this->toFloat() == other.toFloat());
}

bool	Fixed::operator !=(const Fixed &other) const{
	return (this->toFloat() != other.toFloat());
}

/* The 4 arithmetic operators: +, -, *, and /. */
Fixed	Fixed::operator +(const Fixed &other) const{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed	Fixed::operator -(const Fixed &other) const{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed	Fixed::operator *(const Fixed &other) const{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed	Fixed::operator /(const Fixed &other) const{
	if (other.toFloat() == 0.0f)
	{
		std::cerr << ANSI_COLOR_RED << "Error: Division by zero!" << ANSI_COLOR_RESET << std::endl;
		return (Fixed(0));
	}
	return (Fixed(this->toFloat() / other.toFloat()));
}

		/* The 4 increment/decrement (pre-increment and post-increment, pre-decrement and
post-decrement) operators, which will increase or decrease the fixed-point value by
the smallest representable ϵ, such that 1 + ϵ > 1. */

Fixed	&Fixed::operator ++(void){
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator ++(int){
	Fixed temp(*this);
	this->_value++;
	return (temp);
}

Fixed	&Fixed::operator --(void){
	// std::cout << ANSI_COLOR_YELLOW << "Fixed Pre-Decrement Operator called" << ANSI_COLOR_RESET << std::endl;
	this->_value--;
	return (*this);
}
/*
mpについて、以下の懸念を持っています：
tempは演算前の値のコピーを保持している
tempを返すことで<<演算子（toFloat()）に値を渡している
しかし、operator--(int)のスコープを抜けた時にtempのデストラクタが呼ばれて破棄される
そうするとtoFloat()に参照が渡せないのではないか？
これは一時オブジェクトの生存期間に関する重要な質問です。
実際のところ、C++では値で返されるオブジェクトは、その値が使用されるまでの間（通常は式の評価が完了するまで）生存期間が延長されます。つまり：
tempは値として返される（参照ではない）
戻り値として返される時に、tempのコピーが作成されるか、あるいはReturn Value Optimization (RVO)により最適化される
そのコピー（または最適化されたオブジェクト）は、式の評価が完了するまで生存する
<<演算子が呼ばれる時には、そのオブジェクトはまだ有効



*/
	// std::cout << a-- ;
   // この順序で実行されます：
   // 1. a--が評価され、tempが作成・返される
   // 2. <<演算子がtempを受け取る  
   // 3. toFloat()がtempに対して呼ばれる
   // 4. 文全体の評価完了後にtempが破棄される
Fixed	Fixed::operator --(int){
	std::cout << ANSI_COLOR_YELLOW << "Fixed Post-Decrement Operator called" << ANSI_COLOR_RESET << std::endl;
	Fixed temp(*this);
	this->_value--;
	return (temp);
}

std::ostream &operator <<(std::ostream &outputStream, const Fixed &fixed){
	return(outputStream << fixed.toFloat());
}


/*
Fixed	&Fixed::operator --(void){
	std::cout << ANSI_COLOR_YELLOW << "Fixed Pre-Decrement Operator called" << ANSI_COLOR_RESET << std::endl;
	this->_value--;
	return (*this);
}

が関数シグネチャ前方の＆でオブジェクトのアドレス（ポインタ）を返す型を宣言しているので指定子のオブジェクトの
_valueを書き換えた後にそのアドレスを返すことで　<< にオーバーロードされているtoFloteにアドレスを渡すので演算後の値が表示される

というのは理解できました。

一方で
*/