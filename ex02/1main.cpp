/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1main.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:06 by torinoue          #+#    #+#             */
/*   Updated: 2025/08/15 03:15:44 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AnsiColor.hpp"
#include <iostream>
#include "Fixed.hpp"
#include <climits>

int main( void )
{


	// {
	// std::cout << "課題書のテスト:" << std::endl;

	// Fixed a;
	// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl; 
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;
	
	// std::cout << b << std::endl;
	
	// std::cout << Fixed::max( a, b ) << std::endl;
	// }
	// return 0;
			{
					
	// const int MAX_SAFE_INT = INT_MAX / (1 << 8);
		// sqrt(MAX_SAFE_INT)の計算結果をハードコーディング
		// MAX_SAFE_INT = 2147483647 / 256 = 8388607
		// sqrt(8388607) = 2896.31... → Fixed型で2897.31として表示される
		Fixed a(2898.31f);  // sqrt(MAX_SAFE_INT) + 1
		Fixed b(2897.31f);  // sqrt(MAX_SAFE_INT)
		
		// レビュー時の値の根拠確認用（禁止関数使用のためコメントアウト）
		// Fixed a(static_cast<float>(sqrt(MAX_SAFE_INT)) + 1);
		// Fixed b(static_cast<float>(sqrt(MAX_SAFE_INT)));
		
		Fixed c(5.25f);

		std::cout << "a = sqrt(MAX_SAFE_INT) + 1 = " << a << std::endl;
		std::cout << "b = sqrt(MAX_SAFE_INT) = " << b << std::endl;
		std::cout << "c = 5.25f = " << c << std::endl;

		std::cout << "\n比較演算子のテスト:" << std::endl;
		std::cout << "a > b: " << (a > b) << std::endl;
		std::cout << "a < b: " << (a < b) << std::endl;
		std::cout << "b >= c: " << (b >= c) << std::endl;
		std::cout << "a <= b: " << (a <= b) << std::endl;
		std::cout << "b == c: " << (b == c) << std::endl;
		std::cout << "a != b: " << (a != b) << std::endl;

		std::cout << "\n算術演算子のテスト:" << std::endl;
		std::cout << "a + b = " << (a + b) << std::endl;
		std::cout << "a - b = " << (a - b) << std::endl;
		std::cout << "a * b = " << (a * a) << std::endl;
		std::cout << "b * b = " << (b * b) << std::endl;
		std::cout << "getRawBits(b * b) = " << (b * b).getRawBits() << std::endl;
		std::cout << "a / b = " << (a / b) << std::endl;
		
		std::cout << "a / 0 = " << (a / 0) << std::endl;
		return 0;
		
		std::cout << "a / 42 = " << (a / 42) << std::endl;
		std::cout << "42 / a = " << (Fixed(42) / a) << std::endl;

		std::cout << "getRawBits(a) = " << a.getRawBits() << std::endl;
		std::cout << "0 / a = " << (Fixed(0) / a) << std::endl;
		std::cout << "1 / a = " << (Fixed(1) / a) << std::endl;
		std::cout << "a / 1 = " << (a / 1) << std::endl;
		std::cout << "a / 1.0f = " << (a / 1.0f) << std::endl;
		std::cout << "a / 0.03125     = " << (a / (1/32.0f)) << std::endl;
		std::cout << "a / 0.00390625  = " << (a / (1/256.0f)) << std::endl;
		// std::cout << "a / 0.00390624  = " << (a / (1/256.0f - 0.00000001f)) << std::endl;
		std::cout << "\n=== 境界値テスト（ゼロ丸めと最小値丸め） ===" << std::endl;
		
		// Fixed型の最小表現可能値の半分が境界値
		const float MIN_REPRESENTABLE = 1.0f / 256.0f;  // 0.00390625
		const float BOUNDARY = MIN_REPRESENTABLE / 2.0f;  // 0.001953125
		
		std::cout << "最小表現可能値: " << MIN_REPRESENTABLE << std::endl;
		std::cout << "境界値: " << BOUNDARY << std::endl;
		
		// ゼロに丸められる最大の値（境界値未満）
		float zero_rounded_max = BOUNDARY - 0.0000001f;  // 0.0019531149
		std::cout << "\n1. ゼロに丸められる最大の値:" << std::endl;
		std::cout << "入力値: " << zero_rounded_max << std::endl;
		Fixed zero_test(zero_rounded_max);
		std::cout << "結果: " << zero_test << " (getRawBits = " << zero_test.getRawBits() << ")" << std::endl;
		
		// 最小値に丸められる最小の値（境界値ちょうど）
		std::cout << "\n2. 最小値に丸められる最小の値（境界値ちょうど）:" << std::endl;
		std::cout << "入力値: " << BOUNDARY << std::endl;
		Fixed min_test(BOUNDARY);
		std::cout << "結果: " << min_test << " (getRawBits = " << min_test.getRawBits() << ")" << std::endl;
		
		// 境界値より少し大きい値
		float slightly_above = BOUNDARY + 0.0000001f;  // 0.0019531351
		std::cout << "\n3. 境界値より少し大きい値:" << std::endl;
		std::cout << "入力値: " << slightly_above << std::endl;
		Fixed above_test(slightly_above);
		std::cout << "結果: " << above_test << " (getRawBits = " << above_test.getRawBits() << ")" << std::endl;
		
		// 除算テスト（ゼロ除算回避のため、ゼロでない値のみテスト）
		if (min_test.getRawBits() != 0) {
			std::cout << "\n4. 境界値での除算テスト:" << std::endl;
			std::cout << "a / 境界値 = " << (a / min_test) << std::endl;
		}
		if (above_test.getRawBits() != 0) {
			std::cout << "a / 境界値+ε = " << (a / above_test) << std::endl;
		}
		
		std::cout << "\n=== 数学的に正確な境界値テスト ===" << std::endl;
		
		// nextafter()の計算結果をハードコーディング
		// BOUNDARY = 0.001953125f
		float precise_boundary_minus = 0.0019531249f;  // nextafter(BOUNDARY, 0.0f)の近似値
		float precise_boundary_plus = 0.0019531251f;   // nextafter(BOUNDARY, 1.0f)の近似値
		
		// レビュー時の値の根拠確認用（禁止関数使用のためコメントアウト）
		// float precise_boundary_minus = nextafter(BOUNDARY, 0.0f);
		// float precise_boundary_plus = nextafter(BOUNDARY, 1.0f);
		
		std::cout << "境界値の直前: " << precise_boundary_minus << std::endl;
		std::cout << "境界値ちょうど: " << BOUNDARY << std::endl;
		std::cout << "境界値の直後: " << precise_boundary_plus << std::endl;
		
		Fixed precise_minus(precise_boundary_minus);
		Fixed precise_exact(BOUNDARY);
		Fixed precise_plus(precise_boundary_plus);
		
		std::cout << "\n境界値-1ULP: " << precise_minus << " (getRawBits = " << precise_minus.getRawBits() << ")" << std::endl;
		std::cout << "境界値ちょうど: " << precise_exact << " (getRawBits = " << precise_exact.getRawBits() << ")" << std::endl;
		std::cout << "境界値+1ULP: " << precise_plus << " (getRawBits = " << precise_plus.getRawBits() << ")" << std::endl;
		
		return 0;
		// 0.00390625
		// 0.00000001f
		// 0.00390625 - 0.00000001f = 0.00390624
		// 1/256.0f - 0.00000001f   = 0.00390624
		// 1/256.0f - 0.001f        = 0.00390624
		float aaa = 1/256.0f - 0.001f;
		std::cout << "aaa = " << aaa << std::endl;
		std::cout << "a / aaa = " << (a / aaa) << std::endl;

		
		}
		return 0;
	
// 	{
// 	std::cout << "\nインクリメント/デクリメント演算子のテスト:" << std::endl;

// 	Fixed a(42);
// 	std::cout << "a = " << a << std::endl;
// 	std::cout << "a++ = " << (a++) << std::endl;
// 	std::cout << "a = " << a << std::endl;
// 	std::cout << "++a = " << (++a) << std::endl;
// 	std::cout << "a = " << a << std::endl;
// 	std::cout << "a-- = " << (a--) << std::endl;
// 	std::cout << "a = " << a << std::endl;
// 	std::cout << "--a = " << (--a) << std::endl;
// 	std::cout << "a = " << a << std::endl;

// }
// return 0;
// 	{
// 	std::cout << "\nconst オブジェクトでのmin/maxのテスト:" << std::endl;
// 	const Fixed e(30);
// 	const Fixed f(40);
// 	const Fixed g(30);

	
// 	std::cout << "e = " << e << std::endl;
// 	std::cout << "f = " << f << std::endl;
// 	std::cout << "g = " << g << std::endl;
// 	std::cout << "min(e, f) = " << Fixed::min(e, f) << std::endl;
// 	std::cout << "max(e, f) = " << Fixed::max(e, f) << std::endl;
// 	std::cout << "min(e, g) = " << Fixed::min(e, g) << std::endl;
// 	std::cout << "max(e, g) = " << Fixed::max(e, g) << std::endl;
// }
	// return 0;

	// {
	// 	std::cout << "\n非constオブジェクトでのmin/maxのテスト:" << std::endl;
		
	// 	Fixed a(10);
	// 	Fixed b(20);
	// 	Fixed c(10);
	// 	std::cout << "a = " << a << std::endl;
	// 	std::cout << "b = " << b << std::endl;
	// 	std::cout << "c = " << c << std::endl;
	
	// 	std::cout << "min(a, b) = " << Fixed::min(a, b) << std::endl;
	// 	std::cout << "max(a, b) = " << Fixed::max(a, b) << std::endl;
	// 	std::cout << "min(a, c) = " << Fixed::min(a, c) << std::endl;
	// 	std::cout << "max(a, c) = " << Fixed::max(a, c) << std::endl;
		
	// 	std::cout << std::endl;
	// 	std::cout << "&a = " << &a << std::endl;
	// 	std::cout << "&b = " << &b << std::endl;
	// 	std::cout << "&c = " << &c << std::endl;
	
	// 	std::cout << "&max(a, c) = " << &Fixed::max(a, c) << std::endl;
	
	// 	std::cout << std::endl;
	// 	std::cout << "a.getRawBits() = " << a.getRawBits() << std::endl;
	// 	std::cout << "b.getRawBits() = " << b.getRawBits() << std::endl;
	// 	std::cout << "c.getRawBits() = " << c.getRawBits() << std::endl;
	// 	}
	
		// return 0;
	// {
	// 	std::cout << "\nテスト: std::minとFixed::minの比較テスト - アドレス確認" << std::endl;
	// 	std::cout << "注: C++ std::min/maxは等値の場合、第一引数を返す" << std::endl;
	// 	std::cout << "注: このテストでは、int_aとint_bは等値であるため、std::min(int_a, int_b)はint_aを返す" << std::endl;
	// 	int int_a = 10;
	// 	int int_b = 10;
	// 	std::cout << "                 int_a = " << int_a << "                   &int_a = " << &int_a << std::endl;
	// 	std::cout << "                 int_b = " << int_b << "                   &int_b = " << &int_b << std::endl;
	// 	std::cout << "std::min(int_a, int_b) = " << std::min(int_a, int_b) << "  &std::min(int_a, int_b) = " << &std::min(int_a, int_b) << std::endl;
		
	// 	std::cout << std::endl;

	// 	std::cout << "\nFixed::minとstd::minの比較テスト - アドレス確認" << std::endl;
	// 	std::cout << "注: Fixed::minは等値の場合、第一引数を返す" << std::endl;
	// 	Fixed a(10);
	// 	Fixed b(10);
		
	// 	std::cout << "                     a = " << a << "                       &a = " << &a << std::endl;
	// 	std::cout << "                     b = " << b << "                       &b = " << &b << std::endl;
	// 	std::cout << "             min(a, b) = " << Fixed::min(a,b) << "               &min(a, b) = " << &Fixed::min(a, b) << std::endl;

	// }
	// return 0;


}/*
0.00390625 を二進数で表すと 0.00000001 
0.00000001
0.12345678
 */
