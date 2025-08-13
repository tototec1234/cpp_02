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

// ビット表現を視覚化する関数（C++98対応）
void printBits(int value, const char* name) {
	std::cout << name << " bits: ";
	for (int i = 23; i >= 0; i--) {  // 24ビット表示
		if (i == 7) std::cout << "|";  // 整数部と小数部の境界
		std::cout << ((value >> i) & 1);
	}
	std::cout << " (" << value << ")" << std::endl;
	
	// 内訳表示
	int integer_part = value >> 8;
	int fractional_part = value & 0xFF;
	std::cout << "  -> 整数部: " << integer_part << " (0x" << std::hex << integer_part << std::dec << ")";
	std::cout << ", 小数部: " << fractional_part << "/256 = " << std::fixed << std::setprecision(6) << (fractional_part / 256.0) << std::endl;
}

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
		Fixed d, e, f, g, h, i, j, k, l, m, n;
		
		/*
				d.setRawBits(16777215);  // 2^24-1 (フロート精度限界)
		e.setRawBits(16777216);  // 2^24 (フロート精度限界)  
		f.setRawBits(16777217);  // 2^24+1 (フロート精度超過)
*/
		d = Fixed(-8388609);  // アンダーフロー（整数）
		e = Fixed(8388607);   // 最大安全値（整数）
		f = Fixed(8388608);   // オーバーフロー（整数）
		
		// フロート閾値テスト
		g = Fixed(8388607.0f);      // INT_MAX/256 = 8388607.996... → 2147483392（超過）
		h = Fixed(8388607.996f);    // より正確な限界値 → 2147483647（ギリギリ）  
		i = Fixed(8388607.997f);    // 限界超過 → オーバーフロー
		j = Fixed(-8388608.0f);     // 最小値（安全）
		
		// 明確なオーバーフローテスト
		Fixed overflow_test = Fixed(8388608.0f);    // 確実にINT_MAX超過
		Fixed underflow_test = Fixed(-8388609.0f);  // 確実にINT_MIN未満
		
		// 精度安全範囲テスト（桁落ち防止）
		k = Fixed(65535.5f);        // 2^16-1 (精度安全範囲内)
		l = Fixed(65536.5f);        // 2^16 (精度安全範囲境界)
		m = Fixed(65537.5f);        // 2^16+1 (精度警告)
		n = Fixed(8192.5f);         // 小数部テスト: 0.5 = 128/256
		
		// 追加: 8ビット固定小数点の精度テスト
		Fixed o = Fixed(10.00390625f);  // 最小単位の倍数
		Fixed p = Fixed(10.001f);       // 最小単位で表現不可能
		Fixed q = Fixed(10.004f);       // 最小単位に近い値
		
		// ビット列表現テスト（C++98対応）
		Fixed binary_test;
		// 8192.5の内部表現 = 2,097,280
		// ビット表現: 100000000000000010000000 (24ビット)
		//            |________________||______|
		//                整数部8192      小数部0.5
		//                (8192<<8)       (128)
		binary_test.setRawBits(2097280);  // 8192.5
		
		// 桁落ち例のテスト
		Fixed precision_loss_test;
		// 大きな値 + 小さな小数: 65536.5
		// 理論値: 65536.5 * 256 = 16,777,344
		// float計算: 65536.5f * 256 = ? (精度限界で桁落ち可能性)
		precision_loss_test = Fixed(65536.5f);
		
		std::cout << "=== フロートコンストラクタ ===" << std::endl;
		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c is " << c << std::endl;
		
		std::cout << "\n=== 整数境界値テスト ===" << std::endl;
		std::cout << "d is " << d << std::endl;	
		std::cout << "e is " << e << std::endl;
		std::cout << "f is " << f << std::endl;
		
		std::cout << "\n=== フロート境界値テスト ===" << std::endl;
		std::cout << "g is " << g << std::endl;
		std::cout << "h is " << h << std::endl;
		std::cout << "i is " << i << std::endl;
		std::cout << "j is " << j << std::endl;
		
		std::cout << "\n=== 明確なオーバーフローテスト ===" << std::endl;
		std::cout << "overflow_test is " << overflow_test << std::endl;
		std::cout << "underflow_test is " << underflow_test << std::endl;
		
		std::cout << "\n=== 精度安全範囲テスト（桁落ち防止） ===" << std::endl;
		std::cout << "k is " << k << std::endl;
		std::cout << "l is " << l << std::endl;
		std::cout << "m is " << m << std::endl;
		std::cout << "n is " << n << std::endl;
		
		std::cout << "\n=== 8ビット固定小数点精度テスト ===" << std::endl;
		std::cout << "o is " << o << std::endl;
		std::cout << "p is " << p << std::endl;
		std::cout << "q is " << q << std::endl;
		
		// 詳細検証：8192.5の実際の値
		std::cout << "\n=== 8192.5の詳細検証 ===" << std::endl;
		std::cout << "n.getRawBits() = " << n.getRawBits() << std::endl;
		std::cout << "n.toFloat() = " << std::fixed << std::setprecision(6) << n.toFloat() << std::endl;
		std::cout << "Expected: 8192.500000" << std::endl;
		
		std::cout << "\n=== 二進数リテラルテスト ===" << std::endl;
		std::cout << "binary_test.getRawBits() = " << binary_test.getRawBits() << std::endl;
		std::cout << "binary_test.toFloat() = " << std::fixed << std::setprecision(6) << binary_test.toFloat() << std::endl;
		std::cout << "Should match n: " << (n.getRawBits() == binary_test.getRawBits() ? "✓" : "✗") << std::endl;
		
		// 視覚的ビット表現
		std::cout << "\n=== 視覚的ビット表現 ===" << std::endl;
		printBits(n.getRawBits(), "n (8192.5)     ");
		printBits(binary_test.getRawBits(), "binary_test    ");
		
		std::cout << "\n=== 桁落ち例テスト ===" << std::endl;
		std::cout << "precision_loss_test.getRawBits() = " << precision_loss_test.getRawBits() << std::endl;
		std::cout << "precision_loss_test.toFloat() = " << std::fixed << std::setprecision(6) << precision_loss_test.toFloat() << std::endl;
		std::cout << "Expected (theoretical): 65536.500000" << std::endl;
		std::cout << "Actual result shows: " << (precision_loss_test.toFloat() == 65536.5f ? "No loss" : "Precision loss") << std::endl;
		printBits(precision_loss_test.getRawBits(), "precision_loss ");
		return (0);

		std::cout << "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << "b is " << b.toInt() << " as integer" << std::endl;
		std::cout << "c is " << c.toInt() << " as integer" << std::endl;
		std::cout << "d is " << d.toInt() << " as integer" << std::endl;
		std::cout << "e is " << e.toInt() << " as integer" << std::endl;
		std::cout << "f is " << f.toInt() << " as integer" << std::endl;
		std::cout << "g is " << g.toInt() << " as integer" << std::endl;
		std::cout << "h is " << h.toInt() << " as integer" << std::endl;
		std::cout << "i is " << i.toInt() << " as integer" << std::endl;
		std::cout << "j is " << j.toInt() << " as integer" << std::endl;
		std::cout << "k is " << k.toInt() << " as integer" << std::endl;
		std::cout << "l is " << l.toInt() << " as integer" << std::endl;
		std::cout << "m is " << m.toInt() << " as integer" << std::endl;
		std::cout << "n is " << n.toInt() << " as integer" << std::endl;
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
