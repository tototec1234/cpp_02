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
	
	// float精度を考慮した安全な計算
	// INT_MAX = 2147483647, (1 << 8) = 256
	// 理論値: 8388607.996... だが、floatの精度で丸められる
	// 安全のため少し小さい値を使用
	// const float MAX_SAFE_FLOAT = 8388607.5f;  // INT_MAX/256より少し小さい値
	
	// const float MAX_SAFE_FLOAT = 8388607.7f;  // INT_MAX/256より少し小さい値
	// const float MAX_SAFE_FLOAT_PLUS = 8388607.8f;  // INT_MAX/256より少し小さい値
	// const float MIN_SAFE_FLOAT = -8388608.0f; // INT_MIN/256
	const float MIN_SAFE_FLOAT_MINUS = -8388608.6f; // INT_MIN/256
	/*
	std::cout << "Fixed(const float floatingPointNumber) の上限下限テスト" << std::endl;
	
	// std::cout << "\n=== 基本的な浮動小数点数のテスト ===" << std::endl;
	// Fixed test1(1.499f);	
	// Fixed test2(1.501f);
	// Fixed test3(1.498046875f); // 1 + 127/256 (8ビット固定小数点で正確に表現可能)
	// std::cout << "test1(1.499f)=      " << test1 << std::endl;
	// std::cout << "test2(1.501f)=      " << test2 << std::endl;
	// std::cout << "test3(1.498046875f)=" << test3 << std::endl;

	std::cout << "\n=== 境界値テスト ===" << std::endl;
	// Fixed max_safe_float_plus(MAX_SAFE_FLOAT + 1.0f);
	
	// Fixed min_safe_float_minus(MIN_SAFE_FLOAT - 1.0f);
	
	std::cout << "MAX_SAFE_FLOAT=		" << MAX_SAFE_FLOAT << std::endl;
	Fixed max_safe_float(MAX_SAFE_FLOAT);
	std::cout << "max_safe_float=		" << max_safe_float << std::endl;
	std::cout << std::endl;	// std::cout << "max_safe_float_plus= " << max_safe_float_plus << std::endl;
	std::cout << std::endl;	// std::cout << "max_safe_float_plus= " << max_safe_float_plus << std::endl;
	std::cout << "MAX_SAFE_FLOAT_PLUS=	" << MAX_SAFE_FLOAT_PLUS << std::endl;
	Fixed max_safe_float_plus(MAX_SAFE_FLOAT_PLUS);
	std::cout << "max_safe_float_plus=	" << max_safe_float_plus << std::endl;
	std::cout << std::endl;	// std::cout << "max_safe_float_plus= " << max_safe_float_plus << std::endl;
	std::cout << std::endl;	// std::cout << "max_safe_float_plus= " << max_safe_float_plus << std::endl;

	std::cout << "MIN_SAFE_FLOAT=		" << MIN_SAFE_FLOAT << std::endl;
	Fixed min_safe_float(MIN_SAFE_FLOAT);
	std::cout << "min_safe_float=		" << min_safe_float << std::endl;
	
	
	std::cout << std::endl;	// std::cout << "max_safe_float_plus= " << max_safe_float_plus << std::endl;
	std::cout << std::endl;	// std::cout << "max_safe_float_plus= " << max_safe_float_plus << std::endl;
*/
	std::cout << "MIN_SAFE_FLOAT_MINUS=	" << MIN_SAFE_FLOAT_MINUS << std::endl;
	Fixed min_safe_float_minus(MIN_SAFE_FLOAT_MINUS);
	std::cout << "min_safe_float_minus=	" << min_safe_float_minus << std::endl;	
	
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
