/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:06 by torinoue          #+#    #+#             */
/*   Updated: 2025/08/13 20:56:36 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AnsiColor.hpp"
#include <iostream>
#include "Fixed.hpp"

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
	{
		Fixed a;
		// Fixed const b( 10 );
		// Fixed const c( 42.42f );
		// Fixed const d( b );

		// a = Fixed( 1234.4321f );
		a = Fixed( 1.499f );
		Fixed b = Fixed( 1.501f );
		// Fixed c = Fixed( 1.498046875f );
		// Fixed d = Fixed( 100000001.0f);
		// Fixed e = Fixed( 123456789.0f);
		// Fixed f = Fixed( 16777217.0f);
		Fixed c = Fixed( 1.498046875f );
		Fixed d = Fixed( 100000001);
		Fixed e = Fixed( 123456789);
		Fixed f = Fixed( 16777217);
		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c is " << c << std::endl;
		std::cout << "d is " << d << std::endl;	
		std::cout << "e is " << e << std::endl;
		std::cout << "f is " << f << std::endl;
		

		// std::cout << "d is " << d << std::endl;

		// std::cout << "a is " << a.toInt() << " as integer" << std::endl;
		// std::cout << "b is " << b.toInt() << " as integer" << std::endl;
		// std::cout << "c is " << c.toInt() << " as integer" << std::endl;
		// std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	}
	return 0;
}

/*
floatingPointNumber = 1.499 → static_cast<int>: 383, roundf: 384
floatingPointNumber = 1.501 → 両方384
floatingPointNumber = 1.498046875 → static_cast<int>: 383, roundf: 384

例1: _value が大きい場合
_value = 100000001

1 << 8 = 256

static_cast<float>(100000001) / static_cast<float>(256)
→ 390625.00390625

static_cast<float>(100000001) / 256
→ 390625.0

例2: _value が2の冪乗でない場合
_value = 123456789

1 << 8 = 256

static_cast<float>(123456789) / static_cast<float>(256)
→ 482253.08203125

static_cast<float>(123456789) / 256
→ 482253.078125

例3: _value がfloatの精度限界付近の場合
_value = 16777217（floatの精度限界を超える値）

1 << 8 = 256

static_cast<float>(16777217) / static_cast<float>(256)
→ 65536.00390625

static_cast<float>(16777217) / 256
→ 65536.0
*/
