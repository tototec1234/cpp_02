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
		// フロートコンストラクタのテスト
		a = Fixed( 1.499f );
		Fixed b = Fixed( 1.501f );
		Fixed c = Fixed( 1.498046875f );
		
		// 精度差をテストするために特定の内部値を設定
		Fixed d, e, f;
		
		/*
				d.setRawBits(16777215);  // 2^24-1 (フロート精度限界)
		e.setRawBits(16777216);  // 2^24 (フロート精度限界)  
		f.setRawBits(16777217);  // 2^24+1 (フロート精度超過)
*/
		d = Fixed(-8388609);  // 2^24-1 (フロート精度限界)
		e = Fixed(8388607);  // 2^24 (フロート精度限界)  
		f = Fixed(8388608);  //  (2^31-1) / 256

		std::cout << "=== フロートコンストラクタ ===" << std::endl;
		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c is " << c << std::endl;
		
		std::cout << "\n=== 精度差テスト（setRawBits使用） ===" << std::endl;
		std::cout << "d is " << d << std::endl;	
		std::cout << "e is " << e << std::endl;
		std::cout << "f is " << f << std::endl;


		std::cout << "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << "b is " << b.toInt() << " as integer" << std::endl;
		std::cout << "c is " << c.toInt() << " as integer" << std::endl;
		std::cout << "d is " << d.toInt() << " as integer" << std::endl;
		std::cout << "e is " << e.toInt() << " as integer" << std::endl;
		std::cout << "f is " << f.toInt() << " as integer" << std::endl;
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

/*
整数コンストラクタでは値を8ビット左シフトするので、入力できる整数は約 -32,768 から 32,767 の範囲

*/
