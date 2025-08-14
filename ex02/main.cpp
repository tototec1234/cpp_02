/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:06 by torinoue          #+#    #+#             */
/*   Updated: 2025/08/14 15:28:43 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AnsiColor.hpp"
#include <iostream>
#include "Fixed.hpp"
#include <iomanip> // 浮動小数点数の精度を制御するために追加

int main( void )
{
	// {
	// 	Fixed a;
	// 	Fixed b( a );
	// 	Fixed c;
	// 	std::cerr << ANSI_COLOR_BLUE << "Command: c = b;" << ANSI_COLOR_RESET << std::endl;
	// 	c = b;
	// 	std::cout << a.getRawBits() << std::endl;
	// 	std::cout << b.getRawBits() << std::endl;
	// 	std::cout << c.getRawBits() << std::endl;
	// }
	// {
	// 	Fixed a;
	// 	Fixed const b( 10 );
	// 	Fixed const c( 42.42f );
	// 	Fixed const d( b );

	// 	a = Fixed( 1234.4321f );
	
	// 	std::cout << "a is " << a << std::endl;
	// 	std::cout << "b is " << b << std::endl;
	// 	std::cout << "c is " << c << std::endl;
	// 	std::cout << "d is " << d << std::endl;

	// 	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	// 	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	// 	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	// 	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	// }
	// {
		// {
		// Fixed a(10.5f);
		// Fixed b(5.25f);
		// Fixed c(5.25f);

		// std::cout << "比較演算子のテスト:" << std::endl;
		// std::cout << "a > b: " << (a > b) << std::endl;
		// std::cout << "a < b: " << (a < b) << std::endl;
		// std::cout << "b >= c: " << (b >= c) << std::endl;
		// std::cout << "a <= b: " << (a <= b) << std::endl;
		// std::cout << "b == c: " << (b == c) << std::endl;
		// std::cout << "a != b: " << (a != b) << std::endl;

		// std::cout << "\n算術演算子のテスト:" << std::endl;
		// std::cout << "a + b = " << (a + b) << std::endl;
		// std::cout << "a - b = " << (a - b) << std::endl;
		// std::cout << "a * b = " << (a * b) << std::endl;
		// std::cout << "a / b = " << (a / b) << std::endl;
		// std::cout << "a / 0 = " << (a / 0) << std::endl;
		// }
/*
		{
			Fixed a(42);
		std::cout << "\nインクリメント/デクリメント演算子のテスト:" << std::endl;
		std::cout << "a++ = " << (a++) << std::endl;
		std::cout << "a = " << a << std::endl;
		std::cout << "++a = " << (++a) << std::endl;
		std::cout << "a = " << a << std::endl;
		std::cout << "a-- = " << (a--) << std::endl;
		std::cout << "a = " << a << std::endl;
		std::cout << "--a = " << (--a) << std::endl;
		std::cout << "a = " << a << std::endl;

		// std::cout << Fixed::max( a, b ) << std::endl;
	}
	return 0;
	*/
	{
std::cout << std::fixed << std::setprecision(10);

		Fixed a;
		// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

		std::cout << "a = " << a << std::endl;
		// std::cout << "after ++a = " << ++a << std::endl;
		// std::cout << "a-- = " << a-- << std::endl;
		std::cout << "a-- = " << a-- << std::endl;
		std::cout << "a = " << a << std::endl;
		// std::cout << "getRawBits a = " << a.getRawBits() << std::endl;
		// std::cout << "float a = " << a.toFloat() << std::endl;

		// std::cout << a++ << std::endl;
		// std::cout << "after a++ = " ;
		// std::cout << a << std::endl;
		// std::cout << "getRawBits a = " << a.getRawBits() << std::endl;
		// std::cout << "float a = " << a.toFloat() << std::endl;

		// std::cout << "b = " ;
		// std::cout << b << std::endl;

		// std::cout << Fixed::max( a, b ) << std::endl;
	}
	return 0;
}
/*
0.00390625 を二進数で表すと 0.00000001 
0.00000001
0.12345678
 */