/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:06 by torinoue          #+#    #+#             */
/*   Updated: 2025/08/14 20:24:33 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AnsiColor.hpp"
#include <iostream>
#include "Fixed.hpp"
#include <iomanip> // 浮動小数点数の精度を制御するために追加

int main( void )
{
	{
	std::cout << "課題書のテスト:" << std::endl;

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl; 
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;
	
	std::cout << Fixed::max( a, b ) << std::endl;
	}
	return 0;

	{
	std::cout << "\nconst オブジェクトでのmin/maxのテスト:" << std::endl;
	const Fixed e(30);
	const Fixed f(40);
	const Fixed g(30);

	
	std::cout << "e = " << e << std::endl;
	std::cout << "f = " << f << std::endl;
	std::cout << "g = " << g << std::endl;
	std::cout << "min(e, f) = " << Fixed::min(e, f) << std::endl;
	std::cout << "max(e, f) = " << Fixed::max(e, f) << std::endl;
	std::cout << "min(e, g) = " << Fixed::min(e, g) << std::endl;
	std::cout << "max(e, g) = " << Fixed::max(e, g) << std::endl;

	
	std::cout << "&e = " << &e << std::endl;
	std::cout << "&f = " << &f << std::endl;
	std::cout << "&g = " << &g << std::endl;
}
	return 0;

	{
		std::cout << "\n非constオブジェクトでのmin/maxのテスト:" << std::endl;
		
		Fixed a(10);
		Fixed b(20);
		Fixed c(10);
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
		std::cout << "c = " << c << std::endl;
	
		std::cout << "min(a, b) = " << Fixed::min(a, b) << std::endl;
		std::cout << "max(a, b) = " << Fixed::max(a, b) << std::endl;
		std::cout << "min(a, c) = " << Fixed::min(a, c) << std::endl;
		std::cout << "max(a, c) = " << Fixed::max(a, c) << std::endl;
		
		std::cout << std::endl;
		std::cout << "&a = " << &a << std::endl;
		std::cout << "&b = " << &b << std::endl;
		std::cout << "&c = " << &c << std::endl;
	
		std::cout << "&max(a, c) = " << &Fixed::max(a, c) << std::endl;
	
		std::cout << std::endl;
		std::cout << "a.getRawBits() = " << a.getRawBits() << std::endl;
		std::cout << "b.getRawBits() = " << b.getRawBits() << std::endl;
		std::cout << "c.getRawBits() = " << c.getRawBits() << std::endl;
		}
	
		return 0;
	{
		std::cout << "\nテスト: std::minとFixed::minの比較テスト - アドレス確認" << std::endl;
		std::cout << "注: C++ std::min/maxは等値の場合、第一引数を返す" << std::endl;
		std::cout << "注: このテストでは、int_aとint_bは等値であるため、std::min(int_a, int_b)はint_aを返す" << std::endl;
		int int_a = 10;
		int int_b = 10;
		std::cout << "                 int_a = " << int_a << "                   &int_a = " << &int_a << std::endl;
		std::cout << "                 int_b = " << int_b << "                   &int_b = " << &int_b << std::endl;
		std::cout << "std::min(int_a, int_b) = " << std::min(int_a, int_b) << "  &std::min(int_a, int_b) = " << &std::min(int_a, int_b) << std::endl;
		
		std::cout << std::endl;

		std::cout << "\nFixed::minとstd::minの比較テスト - アドレス確認" << std::endl;
		std::cout << "注: Fixed::minは等値の場合、第一引数を返す" << std::endl;
		Fixed a(10);
		Fixed b(10);
		
		std::cout << "                     a = " << a << "                       &a = " << &a << std::endl;
		std::cout << "                     b = " << b << "                       &b = " << &b << std::endl;
		std::cout << "             min(a, b) = " << Fixed::min(a,b) << "               &min(a, b) = " << &Fixed::min(a, b) << std::endl;

		std::cout << std::endl;
		
		std::cout << "------------------" << std::endl;
		std::cout << "min(a, b) = " << std::min(a.getRawBits(), b.getRawBits()) << "       &min(a, b) = " << &std::min(a.getRawBits(), b.getRawBits()) << std::endl;

	}
	return 0;


}
/*
0.00390625 を二進数で表すと 0.00000001 
0.00000001
0.12345678
 */