/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:06 by torinoue          #+#    #+#             */
/*   Updated: 2025/08/15 00:42:28 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AnsiColor.hpp"
#include <iostream>
#include "Fixed.hpp"
#include <iomanip> // 浮動小数点数の精度を制御するために追加
#include <cfloat>  // FLT_EPSILON用
#include <cmath>   // nextafter用

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
					
	const int MAX_SAFE_INT = INT_MAX / (1 << 8);
		Fixed a(static_cast<float>(sqrt(MAX_SAFE_INT)) + 1);
		Fixed b(static_cast<float>(sqrt(MAX_SAFE_INT)));
		// Fixed b(5.25f);
		Fixed c(5.25f);

		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
		std::cout << "c = " << c << std::endl;

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
		
		// 数学的に正確な境界値（nextafter使用）
		float precise_boundary_minus = nextafter(BOUNDARY, 0.0f);  // 境界値の直前の値
		float precise_boundary_plus = nextafter(BOUNDARY, 1.0f);   // 境界値の直後の値
		
		std::cout << "境界値の直前: " << std::fixed << std::setprecision(10) << precise_boundary_minus << std::endl;
		std::cout << "境界値ちょうど: " << std::fixed << std::setprecision(10) << BOUNDARY << std::endl;
		std::cout << "境界値の直後: " << std::fixed << std::setprecision(10) << precise_boundary_plus << std::endl;
		
		Fixed precise_minus(precise_boundary_minus);
		Fixed precise_exact(BOUNDARY);
		Fixed precise_plus(precise_boundary_plus);
		
		std::cout << "\n境界値-1ULP: " << precise_minus << " (getRawBits = " << precise_minus.getRawBits() << ")" << std::endl;
		std::cout << "境界値ちょうど: " << precise_exact << " (getRawBits = " << precise_exact.getRawBits() << ")" << std::endl;
		std::cout << "境界値+1ULP: " << precise_plus << " (getRawBits = " << precise_plus.getRawBits() << ")" << std::endl;
		
		std::cout << std::resetiosflags(std::ios::fixed);
		
		return 0;
		// 0.00390625
		// 0.00000001f
		// 0.00390625 - 0.00000001f = 0.00390624
		// 1/256.0f - 0.00000001f   = 0.00390624
		// 1/256.0f - 0.001f        = 0.00390624
		float aaa = 1/256.0f - 0.001f;
		std::cout << "aaa = " << aaa << std::endl;
		std::cout << "a / aaa = " << (a / aaa) << std::endl;

		std::cout << "\n=== Fixed型の範囲分析 ===" << std::endl;
		
		// Fixed型の最大表現可能値を計算
		const int MAX_REPRESENTABLE = INT_MAX >> 8;  // _fractionalBits = 8
		std::cout << "Fixed型の最大表現可能整数値: " << MAX_REPRESENTABLE << std::endl;
		
		// 理論的な除算結果を計算
		float theoretical_result = a.toFloat() / aaa;
		std::cout << "理論的な a / aaa の結果: " << theoretical_result << std::endl;
		
		// 実際のFixed内部値を確認
		std::cout << "a.getRawBits() = " << a.getRawBits() << std::endl;
		std::cout << "a.toFloat() = " << a.toFloat() << std::endl;
		
		// aaaをFixed型に変換した時の値
		Fixed aaa_fixed(aaa);
		std::cout << "Fixed(aaa).toFloat() = " << aaa_fixed.toFloat() << std::endl;
		std::cout << "Fixed(aaa).getRawBits() = " << aaa_fixed.getRawBits() << std::endl;
		
		// 除算結果の詳細
		Fixed division_result = a / aaa_fixed;
		std::cout << "実際の除算結果.getRawBits() = " << division_result.getRawBits() << std::endl;
		std::cout << "実際の除算結果.toFloat() = " << division_result.toFloat() << std::endl;

		std::cout << "\n=== 最小表現可能値テスト ===" << std::endl;
		
		// 警告が出るケースのテスト
		std::cout << "小さい値のテスト（警告が出るはず）:" << std::endl;
		Fixed small1(0.001f);  // 0.001 < 0.00390625
		Fixed small2(0.0001f); // 0.0001 < 0.00390625
		Fixed small3(-0.002f); // -0.002の絶対値 < 0.00390625
		
		std::cout << "Fixed(0.001f) = " << small1 << std::endl;
		std::cout << "Fixed(0.0001f) = " << small2 << std::endl;
		std::cout << "Fixed(-0.002f) = " << small3 << std::endl;
		
		// 警告が出ないケースのテスト
		std::cout << "\n正常範囲のテスト（警告が出ないはず）:" << std::endl;
		Fixed normal1(0.00390625f); // 最小表現可能値ちょうど
		Fixed normal2(0.005f);      // 最小表現可能値より大きい
		Fixed normal3(0.0f);        // ゼロは警告対象外
		
		std::cout << "Fixed(0.00390625f) = " << normal1 << std::endl;
		std::cout << "Fixed(0.005f) = " << normal2 << std::endl;
		std::cout << "Fixed(0.0f) = " << normal3 << std::endl;

		std::cout << "\n=== NaN・無限大のテスト ===" << std::endl;
		
		// ゼロ除算テスト
		std::cout << "5 / 0 = " << (Fixed(5) / Fixed(0)) << std::endl;
		std::cout << "-5 / 0 = " << (Fixed(-5) / Fixed(0)) << std::endl;
		std::cout << "0 / 0 = " << (Fixed(0) / Fixed(0)) << std::endl;
		
		// 特別な値の生成・検出テスト
		Fixed nan_val = Fixed::getNaN();
		Fixed pos_inf = Fixed::getPositiveInfinity();
		Fixed neg_inf = Fixed::getNegativeInfinity();
		
		std::cout << "\n特別な値の表示:" << std::endl;
		std::cout << "NaN = " << nan_val << std::endl;
		std::cout << "+∞ = " << pos_inf << std::endl;
		std::cout << "-∞ = " << neg_inf << std::endl;
		
		std::cout << "\n特別な値の検出:" << std::endl;
		std::cout << "nan_val.isNaN() = " << nan_val.isNaN() << std::endl;
		std::cout << "pos_inf.isInfinite() = " << pos_inf.isInfinite() << std::endl;
		std::cout << "neg_inf.isNegativeInfinity() = " << neg_inf.isNegativeInfinity() << std::endl;
		
		std::cout << "\nNaNを含む演算:" << std::endl;
		std::cout << "NaN + 5 = " << (nan_val + Fixed(5)) << std::endl;
		std::cout << "5 / NaN = " << (Fixed(5) / nan_val) << std::endl;
		
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


}
/*
0.00390625 を二進数で表すと 0.00000001 
0.00000001
0.12345678
 */