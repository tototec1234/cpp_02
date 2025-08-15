/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torinoue <torinoue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:06 by torinoue          #+#    #+#             */
/*   Updated: 2025/08/15 18:07:41 by torinoue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AnsiColor.hpp"
#include <iostream>
#include "Fixed.hpp"

void test_subject_original();
void test_subject_const();
void test_integer_overflow();
void test_float_minimum_representable();
void test_float_overflow();
void test_edge_cases();

int main( void )
{
	int choice;

	while (true) {
		std::cout << "\nSelect a test to run                    (選択してテストを実行):\n";
		std::cout << "1. Original Subject Tests                 (元の課題書テスト)\n";
		std::cout << "2. Const Type Subject Tests               (課題書const型テスト)\n";
		std::cout << "3. Integer Overflow Tests                 (整数オーバーフローテスト)\n";
		std::cout << "4. Float Minimum Representable Tests      (浮動小数点最小表現可能値テスト)\n";
		std::cout << "5. Float Overflow Tests                   (浮動小数点オーバーフローテスト)\n";
		std::cout << "6. Edge Cases and Other Tests             (エッジケースとその他テスト)\n";
		std::cout << "0. Exit                                   (終了)\n";
		std::cout << "Enter your choice                         (選択してください): ";

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
				test_subject_original();
				break;
			case 2:
				test_subject_const();
				break;
			case 3:
				test_integer_overflow();
				break;
			case 4:
				test_float_minimum_representable();
				break;
			case 5:
				test_float_overflow();
				break;
			case 6:
				test_edge_cases();
				break;
			default:
				std::cout << "Invalid choice. Please try again.\n";
		}
	}
	return 0;
}

void test_subject_original() {
	std::cout << ANSI_COLOR_CYAN << "\n=== 元の課題書テスト ===" << ANSI_COLOR_RESET << std::endl;
	{
		Fixed a;
		Fixed b( 10 );
		Fixed c( 42.42f );
		Fixed d( b );

		b.setRawBits(98);
		a = Fixed( 1234.4321f );

		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c is " << c << std::endl;
		std::cout << "d is " << d << std::endl;

		std::cout << "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << "b is " << b.toInt() << " as integer" << std::endl;
		std::cout << "c is " << c.toInt() << " as integer" << std::endl;
		std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	}
}

void test_subject_const() {
	std::cout << ANSI_COLOR_CYAN << "\n=== 課題書const型テスト ===" << ANSI_COLOR_RESET << std::endl;
	{
		Fixed a;
		Fixed const b( 10 );
		Fixed const c( 42.42f );
		Fixed const d( b );

		a = Fixed( 1234.4321f );

		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c is " << c << std::endl;
		std::cout << "d is " << d << std::endl;

		std::cout << "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << "b is " << b.toInt() << " as integer" << std::endl;
		std::cout << "c is " << c.toInt() << " as integer" << std::endl;
		std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	}
}

void test_integer_overflow() {
	std::cout << ANSI_COLOR_CYAN << "\n=== 整数オーバーフロー/アンダーフローテスト ===" << ANSI_COLOR_RESET << std::endl;
	{
		std::cout << ANSI_COLOR_GREEN << "正常範囲の値: 8388607 (INT_MAX/256), -8388608 (INT_MIN/256)" << ANSI_COLOR_RESET << std::endl;
		Fixed safe_max(8388607);
		Fixed safe_min(-8388608);
		std::cout << "safe_max: " << safe_max << " 2^(31-8)-1"<< std::endl;
		std::cout << "safe_min: " << safe_min << "-2^(31-8)"<< std::endl;

		std::cout << ANSI_COLOR_MAGENTA << "オーバーフロー値: 8388608 (INT_MAX/256 + 1)" << ANSI_COLOR_RESET << std::endl;
		Fixed overflow_test(8388608);
		std::cout << "overflow_test: " << overflow_test <<  " 2^(31-8)-1+1"<<std::endl;

		std::cout << ANSI_COLOR_MAGENTA << "アンダーフロー値: -8388609 (INT_MIN/256 - 1)" << ANSI_COLOR_RESET << std::endl;
		Fixed underflow_test(-8388609);
		std::cout << "underflow_test: " << underflow_test <<  "-2^(31-8)-1"<<std::endl;
	}
}

void test_float_minimum_representable() {
	std::cout << ANSI_COLOR_CYAN << "\n=== 浮動小数点最小表現可能値テスト ===" << ANSI_COLOR_RESET << std::endl;
	{
		std::cout << ANSI_COLOR_GREEN << "最小表現可能値付近: 0.00390625 (1/256)" << ANSI_COLOR_RESET << std::endl;
		Fixed min_representable(0.00390625f);
		std::cout << "min_representable (0.00390625f): " << min_representable << std::endl;

		std::cout << ANSI_COLOR_BLUE << "境界値テスト: 0.00195312 (1/512)" << ANSI_COLOR_RESET << std::endl;
		Fixed boundary_test(0.00195312f);
		std::cout << "boundary_test (0.00195312f): " << boundary_test << std::endl;

		std::cout << ANSI_COLOR_BLUE << "境界値より小さい値（0に丸められる）: 0.001" << ANSI_COLOR_RESET << std::endl;
		Fixed very_small(0.001f);
		std::cout << "very_small (0.001f): " << very_small << std::endl;

		std::cout << ANSI_COLOR_BLUE << "負の小さい値: -0.001, -0.00195312" << ANSI_COLOR_RESET << std::endl;
		Fixed negative_small(-0.001f);
		std::cout << "negative_small (-0.001f): " << negative_small << std::endl;

		Fixed negative_boundary(-0.00195312f);
		std::cout << "negative_boundary (-0.00195312f): " << negative_boundary << std::endl;
	}
}

void test_float_overflow() {
	std::cout << ANSI_COLOR_CYAN << "\n=== 浮動小数点オーバーフロー/アンダーフローテスト ===" << ANSI_COLOR_RESET << std::endl;
	{
		std::cout << ANSI_COLOR_MAGENTA << "大きな値: 99999999.9" << ANSI_COLOR_RESET << std::endl;
		Fixed large_float(99999999.9f);
		std::cout << "large_float (99999999.9f): " << large_float << std::endl;

		std::cout << ANSI_COLOR_MAGENTA << "小さな値: -99999999.9" << ANSI_COLOR_RESET << std::endl;
		Fixed small_float(-99999999.9f);
		std::cout << "small_float (-99999999.9f): " << small_float << std::endl;
	}
}

void test_edge_cases() {
	std::cout << ANSI_COLOR_CYAN << "\n=== エッジケースとその他のテスト ===" << ANSI_COLOR_RESET << std::endl;
	{
		std::cout << ANSI_COLOR_GREEN << "ゼロ値テスト: 0 (int), 0.0 (float)" << ANSI_COLOR_RESET << std::endl;
		Fixed zero_int(0);
		Fixed zero_float(0.0f);
		std::cout << "zero_int: " << zero_int << std::endl;
		std::cout << "zero_float: " << zero_float << std::endl;

		std::cout << ANSI_COLOR_GREEN << "1の値テスト: 1 (int), 1.0 (float)" << ANSI_COLOR_RESET << std::endl;
		Fixed one_int(1);
		Fixed one_float(1.0f);
		std::cout << "one_int: " << one_int << std::endl;
		std::cout << "one_float: " << one_float << std::endl;

		std::cout << ANSI_COLOR_GREEN << "負の値テスト: -42 (int), -3.14 (float)" << ANSI_COLOR_RESET << std::endl;
		Fixed negative_int(-42);
		Fixed negative_float(-3.14f);
		std::cout << "negative_int (-42): " << negative_int << std::endl;
		std::cout << "negative_float (-3.14f): " << negative_float << std::endl;

		std::cout << ANSI_COLOR_GREEN << "小数精度テスト: 0.5, 0.25, 0.125" << ANSI_COLOR_RESET << std::endl;
		Fixed precision_test1(0.5f);
		Fixed precision_test2(0.25f);
		Fixed precision_test3(0.125f);
		std::cout << "precision_test1 (0.5f): " << precision_test1 << std::endl;
		std::cout << "precision_test2 (0.25f): " << precision_test2 << std::endl;
		std::cout << "precision_test3 (0.125f): " << precision_test3 << std::endl;

		std::cout << ANSI_COLOR_GREEN << "getRawBits/setRawBitsテスト: 初期値0, setRawBits(256)" << ANSI_COLOR_RESET << std::endl;
		Fixed raw_test;
		std::cout << "raw_test initial getRawBits: " << raw_test.getRawBits() << std::endl;
		raw_test.setRawBits(256);
		std::cout << "raw_test after setRawBits(256): " << raw_test << std::endl;
		std::cout << "raw_test getRawBits: " << raw_test.getRawBits() << std::endl;
	}
}

 /*
 sed -i '' 's/^[[:space:]]*$//' *.cpp
 */