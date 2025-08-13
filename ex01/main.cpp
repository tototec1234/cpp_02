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
	// const float MAX_SAFE_FLOAT = static_cast<float>(INT_MAX) / (1 << 8);
	// const float MIN_SAFE_FLOAT = static_cast<float>(INT_MIN) / (1 << 8);
	
	// std::cout << "Fixed(const float floatingPointNumber) の上限下限テスト" << std::endl;
	// Fixed test1(1.499f);	
	// Fixed test2(1.501f);
	// Fixed test3(1.498046875f);

	// std::cout << "test1=" << test1 << std::endl;
	// std::cout << "test2=" << test2 << std::endl;
	// std::cout << "test3=" << test3 << std::endl;

	std::cout << "\n\nMAX_SAFE_FLOAT MIN_SAFE_FLOAT 境界値テスト" << std::endl;
	
	// Fixed max_safe_float(MAX_SAFE_FLOAT);

	// std::cout << "MAX_SAFE_FLOAT=		 " << MAX_SAFE_FLOAT << std::endl;
	// std::cout << "max_safe_float=		 " << max_safe_float << std::endl;
	// Fixed max_safe_float_plus(MAX_SAFE_FLOAT + 1.0f	);
	// std::cout << "MAX_SAFE_FLOAT+1.0f=	 " << MAX_SAFE_FLOAT + 1.0f << std::endl;
	// std::cout << "max_safe_float_plus=	 " << max_safe_float_plus << std::endl;
	
	// 科学記法テスト
	float test_float = 8388608.0f;
	float test_float_plus = 8388608.0f + 0.5f;
	float test_float_plus_plus = 8388608.0f + 0.75f;
	Fixed scientific_test1(test_float);  // 科学記法
	Fixed scientific_test2(test_float_plus);    // 通常記法（同じ値）
	Fixed scientific_test3(test_float_plus_plus);    // 通常記法（同じ値）
	
	// より明確な差を出すテスト
	float smaller_test = 65536.5f;    // 2^16 + 0.5 (精度内)
	float smaller_test2 = 65536.25f;  // 2^16 + 0.25 (精度内)
	float smaller_test3 = 65536.125f; // 2^16 + 0.125 (精度内)
	Fixed smaller_fixed1(smaller_test);
	Fixed smaller_fixed2(smaller_test2);
	Fixed smaller_fixed3(smaller_test3);
	
	std::cout << "\n=== 科学記法テスト ===" << std::endl;
	std::cout << "test_float=			" << test_float << std::endl;
	std::cout << "test_float_plus=		" << test_float_plus << std::endl;
	std::cout << "test_float_plus_plus=	" << test_float_plus_plus << std::endl;
	std::cout << "scientific_test1=		" << scientific_test1 << std::endl;
	std::cout << "scientific_test2=		" << scientific_test2 << std::endl;
	std::cout << "scientific_test3=		" << scientific_test3 << std::endl;
	
	std::cout << "\n=== 精度内での差テスト ===" << std::endl;
	std::cout << "smaller_test (65536.5)=	" << smaller_test << " -> " << smaller_fixed1 << std::endl;
	std::cout << "smaller_test2 (65536.25)=	" << smaller_test2 << " -> " << smaller_fixed2 << std::endl;
	std::cout << "smaller_test3 (65536.125)=	" << smaller_test3 << " -> " << smaller_fixed3 << std::endl;
	
	// roundf効果テスト
	std::cout << "\n=== roundf関数の効果テスト ===" << std::endl;
	Fixed roundf_test1(10.1234f);   // 乗算結果が非整数
	Fixed roundf_test2(10.6789f);   // 乗算結果が非整数
	Fixed roundf_test3(10.4999f);   // 境界値
	Fixed roundf_test4(10.5001f);   // 境界値
	
	std::cout << "10.1234f -> " << roundf_test1 << std::endl;
	std::cout << "10.6789f -> " << roundf_test2 << std::endl;
	std::cout << "10.4999f -> " << roundf_test3 << std::endl;
	std::cout << "10.5001f -> " << roundf_test4 << std::endl;
	/*
	Fixed min_safe_float(MIN_SAFE_FLOAT);
	std::cout << "MIN_SAFE_FLOAT=		" ;
	printBits(min_safe_float.getRawBits(), "MIN_SAFE_FLOAT") ;
	std::cout << "\nMIN_SAFE_FLOAT=		" << MIN_SAFE_FLOAT << std::endl;
	std::cout << "min_safe_float=		" << min_safe_float << std::endl;
	Fixed min_safe_float_minus(MIN_SAFE_FLOAT / 2);
	std::cout << "min_safe_float_minus=	" ;
	printBits(min_safe_float_minus.getRawBits(), "min_safe_float_minus") ;
	std::cout << "min_safe_float_minus=	" << min_safe_float_minus << std::endl;
*/
	
	
	
	
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
