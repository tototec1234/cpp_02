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
#include <iomanip> // 浮動小数点数の精度を制御するために追加

int main( void )
{
	{
		std::cout << "=== 整数境界値テスト ===" << std::endl;
		
		// 最大安全値とその前後のテスト
		Fixed max_safe = Fixed(8388607);     // 最大安全値（INT_MAX/256）
		Fixed max_over = Fixed(8388608);     // オーバーフロー（整数）
		Fixed max_under = Fixed(8388606);    // 最大安全値-1
		
		// 最小安全値とその前後のテスト
		Fixed min_safe = Fixed(-8388608);    // 最小安全値（INT_MIN/256）
		Fixed min_under = Fixed(-8388609);   // アンダーフロー（整数）
		Fixed min_over = Fixed(-8388607);    // 最小安全値+1
		
		// 通常の値のテスト
		Fixed zero = Fixed(0);
		Fixed positive = Fixed(100);
		Fixed negative = Fixed(-100);
		
		std::cout << "\n--- 最大値付近 ---" << std::endl;
		std::cout << "max_under (8388606) : " << max_under << " (toFloat: " << std::fixed << std::setprecision(6) << max_under.toFloat() << ")" << std::endl;
		std::cout << "max_safe (8388607)  : " << max_safe << " (toFloat: " << max_safe.toFloat() << ")" << std::endl;
		std::cout << "max_over (8388608)  : " << max_over << " (toFloat: " << max_over.toFloat() << ")" << std::endl;
		
		std::cout << "\n--- 最小値付近 ---" << std::endl;
		std::cout << "min_over (-8388607) : " << min_over << " (toFloat: " << min_over.toFloat() << ")" << std::endl;
		std::cout << "min_safe (-8388608) : " << min_safe << " (toFloat: " << min_safe.toFloat() << ")" << std::endl;
		std::cout << "min_under (-8388609): " << min_under << " (toFloat: " << min_under.toFloat() << ")" << std::endl;
		
		std::cout << "\n--- 通常の値 ---" << std::endl;
		std::cout << "zero (0)            : " << zero << " (toFloat: " << zero.toFloat() << ")" << std::endl;
		std::cout << "positive (100)      : " << positive << " (toFloat: " << positive.toFloat() << ")" << std::endl;
		std::cout << "negative (-100)     : " << negative << " (toFloat: " << negative.toFloat() << ")" << std::endl;
		
		std::cout << "\n--- toInt()での確認 ---" << std::endl;
		std::cout << "max_safe.toInt()    : " << max_safe.toInt() << std::endl;
		std::cout << "max_over.toInt()    : " << max_over.toInt() << std::endl;
		std::cout << "min_safe.toInt()    : " << min_safe.toInt() << std::endl;
		std::cout << "min_under.toInt()   : " << min_under.toInt() << std::endl;
	}
	return 0;
}

/*
整数コンストラクタでは値を8ビット左シフトするので、入力できる整数は約 -8388608 から 8388607 の範囲
最大安全値: INT_MAX / 256 = 8388607
最小安全値: INT_MIN / 256 = -8388608
*/
