/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torinoue <torinoue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:06 by torinoue          #+#    #+#             */
/*   Updated: 2025/08/15 17:20:23 by torinoue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AnsiColor.hpp"
#include <iostream>
#include "Fixed.hpp"
#include <climits>

void test_subject();
void test_arithmetic_operations();
void test_general_arithmetic_operations();
void test_boundary_values();
void test_overflow_cases();
void test_increment_decrement();
void test_const_min_max();
void test_non_const_min_max();
void test_std_min_comparison();

int main(void) {
	int choice;

	while (true) {
		std::cout << "\nSelect a test to run (選択してテストを実行):\n";
		std::cout << "1. Subject Tests (課題書のテスト)\n";
		std::cout << "2. Arithmetic Operations Tests (算術演算テスト)\n";
		std::cout << "3. General Arithmetic Tests (一般的な算術演算テスト)\n";
		std::cout << "4. Boundary Values Tests (境界値テスト)\n";
		std::cout << "5. Overflow Cases Tests (オーバーフローケーステスト)\n";
		std::cout << "6. Increment/Decrement Tests (インクリメント/デクリメントテスト)\n";
		std::cout << "7. Const min/max Tests (定数のmin/maxテスト)\n";
		std::cout << "8. Non-const min/max Tests (非定数のmin/maxテスト)\n";
		std::cout << "9. std::min Comparison Tests (std::min比較テスト)\n";
		std::cout << "0. Exit (終了)\n";
		std::cout << "Enter your choice (選択してください): ";

		if (!(std::cin >> choice)) {
			std::cout << "Invalid input. Please enter a number.\n";
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			continue;
		}

		switch (choice) {
			case 0:
				return 0;
			case 1:
				test_subject();
				break;
			case 2:
				test_arithmetic_operations();
				break;
			case 3:
				test_general_arithmetic_operations();
				break;
			case 4:
				test_boundary_values();
				break;
			case 5:
				test_overflow_cases();
				break;
			case 6:
				test_increment_decrement();
				break;
			case 7:
				test_const_min_max();
				break;
			case 8:
				test_non_const_min_max();
				break;
			case 9:
				test_std_min_comparison();
				break;
			default:
				std::cout << "Invalid choice. Please try again.\n";
		}
	}
	return 0;
}

void test_subject() {
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

// Fixed a(2898.31f);  // sqrt(MAX_SAFE_INT) + 1
// Fixed b(2897.31f);  // sqrt(MAX_SAFE_INT)
void test_arithmetic_operations() {
	std::cout << "\n算術演算子のテスト:" << std::endl;

	Fixed a(2898.31f);
	Fixed b(2897.31f);
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
	std::cout << "a * a = " << (a * a) << std::endl;
	std::cout << "b * b = " << (b * b) << std::endl;
	std::cout << "getRawBits(b * b) = " << (b * b).getRawBits() << std::endl;
	std::cout << "a / b = " << (a / b) << std::endl;

	std::cout << "a / 42 = " << (a / 42) << std::endl;
	std::cout << "42 / a = " << (Fixed(42) / a) << std::endl;
	std::cout << "getRawBits(a) = " << a.getRawBits() << std::endl;
	std::cout << "0 / a = " << (Fixed(0) / a) << std::endl;
	std::cout << "1 / a = " << (Fixed(1) / a) << std::endl;
	std::cout << "a / 1 = " << (a / 1) << std::endl;
	std::cout << "a / 1.0f = " << (a / 1.0f) << std::endl;
	std::cout << "a / 0.03125 = " << (a / (1/32.0f)) << std::endl;
	std::cout << "a / 0.00390625 = " << (a / (1/256.0f)) << std::endl;
}

void test_general_arithmetic_operations() {
	std::cout << "\n一般的な数値での算術演算子のテスト:" << std::endl;
	
	Fixed x(10.5f);
	Fixed y(3.25f);
	Fixed z(-2.75f);
	Fixed w(100);
	
	std::cout << "x = " << x << std::endl;
	std::cout << "y = " << y << std::endl;
	std::cout << "z = " << z << std::endl;
	std::cout << "w = " << w << std::endl;

	std::cout << "\n加算テスト:" << std::endl;
	std::cout << "x + y = " << (x + y) << std::endl;
	std::cout << "x + z = " << (x + z) << std::endl;
	std::cout << "y + w = " << (y + w) << std::endl;

	std::cout << "\n減算テスト:" << std::endl;
	std::cout << "x - y = " << (x - y) << std::endl;
	std::cout << "w - x = " << (w - x) << std::endl;
	std::cout << "y - z = " << (y - z) << std::endl;

	std::cout << "\n乗算テスト:" << std::endl;
	std::cout << "x * y = " << (x * y) << std::endl;
	std::cout << "z * z = " << (z * z) << std::endl;
	std::cout << "y * 2 = " << (y * 2) << std::endl;

	std::cout << "\n除算テスト:" << std::endl;
	std::cout << "w / x = " << (w / x) << std::endl;
	std::cout << "x / y = " << (x / y) << std::endl;
	std::cout << "z / -1 = " << (z / -1) << std::endl;

	std::cout << "\n比較演算子テスト:" << std::endl;
	std::cout << "x > y: " << (x > y) << std::endl;
	std::cout << "z < y: " << (z < y) << std::endl;
	std::cout << "w >= x: " << (w >= x) << std::endl;
	std::cout << "y <= x: " << (y <= x) << std::endl;
	std::cout << "x == Fixed(10.5f): " << (x == Fixed(10.5f)) << std::endl;
	std::cout << "z != y: " << (z != y) << std::endl;
}

void test_boundary_values() {
	std::cout << "\n=== 境界値テスト（ゼロ丸めと最小値丸め） ===" << std::endl;

	const float MIN_REPRESENTABLE = 1.0f / 256.0f;  // 0.00390625
	const float BOUNDARY = MIN_REPRESENTABLE / 2.0f;  // 0.001953125

	std::cout << "最小表現可能値: " << MIN_REPRESENTABLE << std::endl;
	std::cout << "境界値　　　　: " << BOUNDARY << std::endl;
	std::cout << "境界値　　　　: 0.001953125 <-- ハードコーディングされた数字です" << std::endl;

	float zero_rounded_max = BOUNDARY - 0.0000001f;  // 0.0019531149
	std::cout << "\n1. ゼロに丸められる最大の値:" << std::endl;
	std::cout << "入力値　　　　: " << zero_rounded_max << std::endl;
	std::cout << "入力値　　　　: 0.0019531149 <-- ハードコーディングされた数字です" << std::endl;
	
	Fixed zero_test(zero_rounded_max);
	std::cout << "結果: " << zero_test << " (getRawBits = " << zero_test.getRawBits() << ")" << std::endl;

	std::cout << "\n2. 最小値に丸められる最小の値（境界値ちょうど）:" << std::endl;
	std::cout << "入力値　　　　: " << BOUNDARY << std::endl;
	std::cout << "入力値　　　　: 0.001953125 <-- ハードコーディングされた数字です" << std::endl;

	Fixed min_test(BOUNDARY);
	std::cout << "結果: " << min_test << " (getRawBits = " << min_test.getRawBits() << ")" << std::endl;

	float slightly_above = BOUNDARY + 0.0000001f;  // 0.0019531351
	std::cout << "\n3. 境界値より少し大きい値:" << std::endl;
	std::cout << "入力値　　　　: " << slightly_above << std::endl;
	std::cout << "入力値　　　　: 0.0019531351 <-- ハードコーディングされた数字です" << std::endl;
	
	Fixed above_test(slightly_above);
	std::cout << "結果: " << above_test << " (getRawBits = " << above_test.getRawBits() << ")" << std::endl;

	if (min_test.getRawBits() != 0) {
		std::cout << "\n4. 境界値での除算テスト:" << std::endl;
		std::cout << "Fixed(2898.31f)  / 境界値 　= " << (Fixed(2898.31f) / min_test) << std::endl;
		std::cout << "2898.31005859375F  / Fixed(0.001953125) <-- ハードコーディングされた数字です\n" << std::endl;
	}
	if (above_test.getRawBits() != 0) {
		std::cout << "Fixed(2898.31f)  / 境界値+ε = " << (Fixed(2898.31f) / above_test) << std::endl;
		std::cout << "2898.31005859375F  / Fixed(0.0019531351) <-- ハードコーディングされた数字です" << std::endl;

	}

	std::cout << "\n=== 数学的に正確な境界値テスト ===" << std::endl;

	float precise_boundary_minus = 0.0019531249f;
	float precise_boundary_plus  = 0.0019531251f;

	std::cout << "境界値    　: 0.0019531250f <-- ハードコーディングされた数字です" << std::endl;
	std::cout << "        ε　: 0.0000001f ≠ ULP (Unit in the Last Place)" << std::endl;
	std::cout << "境界値 - ε　: " << precise_boundary_minus << std::endl;
	std::cout << "境界値 - ε　: 0.0019531249f <-- ハードコーディングされた数字です" << std::endl;
	Fixed precise_minus(precise_boundary_minus);
	std::cout << "  境界値 - ε: " << precise_minus << " (getRawBits = " << precise_minus.getRawBits() << ")" << std::endl;
	std::cout << std::endl;
	
	std::cout << "境界値ちょうど: " << BOUNDARY << std::endl;
	std::cout << "境界値ちょうど: 0.001953125 <-- ハードコーディングされた数字です" << std::endl;
	Fixed precise_exact(BOUNDARY);
	std::cout << "境界値ちょうど: " << precise_exact << " (getRawBits = " << precise_exact.getRawBits() << ")" << std::endl;
	std::cout << std::endl;

	std::cout << "境界値 + ε　: " << precise_boundary_plus << std::endl;
	std::cout << "境界値 + ε　: 0.0019531251f <-- ハードコーディングされた数字です" << std::endl;
	Fixed precise_plus(precise_boundary_plus);
	std::cout << "境界値 + ε　: " << precise_plus << " (getRawBits = " << precise_plus.getRawBits() << ")" << std::endl;
	std::cout << std::endl;
}

void test_overflow_cases() {
	std::cout << "\n=== オーバーフローケーステスト ===" << std::endl;

	Fixed a(2898.31f);

	std::cout << "\n大きな値のテスト:" << std::endl;
	Fixed large1(32767.0f);
	Fixed large2(32766.0f);

	std::cout << "large1 =  2^15 - 1 = " << large1 << std::endl;
	std::cout << "  getRawBits: " << large1.getRawBits() << std::endl;
	std::cout << "large2 =  2^15 - 2 = " << large2 << std::endl;
	std::cout << "  getRawBits: " << large2.getRawBits() << std::endl;
	std::cout << "large1 + large2 = 2^15 - 1 + 2^15 - 2 = " << (large1 + large2) << std::endl;
	std::cout << "  getRawBits: " << (large1 + large2).getRawBits() << std::endl;
	std::cout << "large1 * large1 = (2^15 - 1) * (2^15 - 1) = " << (large1 * large1) << std::endl;
	std::cout << "  getRawBits: " << (large1 * large1).getRawBits() << std::endl;
	std::cout << "large1 * large2 = (2^15 - 1) * (2^15 - 2) = " << (large1 * large2) << std::endl;
	std::cout << "  getRawBits: " << (large1 * large2).getRawBits() << std::endl;

	std::cout << "\n負の値のテスト:" << std::endl;
	Fixed neg1(-32767.0f);
	Fixed neg2(-1.0f);

	std::cout << "neg1 = " << neg1 << std::endl;
	std::cout << "neg2 = " << neg2 << std::endl;
	std::cout << "neg1 + neg2 = " << (neg1 + neg2) << std::endl;
	std::cout << "neg1 * neg2 =  " << (neg1 * neg2) << std::endl;
	
	std::cout << "ゼロ除算テスト:" << std::endl;
	std::cout << "a / 0 = " << (a / 0) << std::endl;
}

void test_increment_decrement() {
	std::cout << "\nインクリメント/デクリメント演算子のテスト:" << std::endl;

	Fixed a(42);
	std::cout << "a = " << a << std::endl;
	std::cout << "a++ = " << (a++) << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "++a = " << (++a) << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "a-- = " << (a--) << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "--a = " << (--a) << std::endl;
	std::cout << "a = " << a << std::endl;
}

void test_const_min_max() {
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
}

void test_non_const_min_max() {
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

void test_std_min_comparison() {
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
}

/*
0.00390625 を二進数で表すと 0.00000001 
0.00000001
0.12345678
 */

 /*
 sed -i '' 's/^[[:space:]]*$//' *.cpp
 */