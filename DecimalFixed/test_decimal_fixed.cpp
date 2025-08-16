/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_decimal_fixed.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 xx:xx:xx by toruinoue          #+#    #+#             */
/*   Updated: 2025/01/27 xx:xx:xx by toruinoue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "DecimalFixed.hpp"
#include <iostream>
#include <iomanip>
#include <bitset>
#include <vector>
#include <cmath>
#include <cstdlib>

void printSeparator(const std::string &title) {
	std::cout << "\n" << ANSI_COLOR_CYAN << "=== " << title << " ===" << ANSI_COLOR_RESET << std::endl;
}

void testPrecision() {
	printSeparator("精度比較テスト: 42.42");
	
	// 従来のFixed型
	Fixed original_fixed(42.42f);
	std::cout << ANSI_COLOR_GREEN << "従来のFixed(42.42f): " << original_fixed << ANSI_COLOR_RESET << std::endl;
	std::cout << "  toFloat(): " << std::fixed << std::setprecision(10) << original_fixed.toFloat() << std::endl;
	std::cout << "  rawBits: " << original_fixed.getRawBits() << " (0x" << std::hex << original_fixed.getRawBits() << std::dec << ")" << std::endl;
	
	// 新しいDecimalFixed型
	DecimalFixed decimal_fixed("42.42");
	std::cout << ANSI_COLOR_BLUE << "新しいDecimalFixed(\"42.42\"): " << decimal_fixed << ANSI_COLOR_RESET << std::endl;
	std::cout << "  toDouble(): " << std::fixed << std::setprecision(10) << decimal_fixed.toDouble() << std::endl;
	std::cout << "  rawBits: " << decimal_fixed.getRawBits() << " (0x" << std::hex << decimal_fixed.getRawBits() << std::dec << ")" << std::endl;
	
	// 精度の差を表示
	double diff = std::abs(42.42 - original_fixed.toFloat());
	std::cout << ANSI_COLOR_YELLOW << "従来のFixed型の誤差: " << std::scientific << diff << ANSI_COLOR_RESET << std::endl;
	
	diff = std::abs(42.42 - decimal_fixed.toDouble());
	std::cout << ANSI_COLOR_YELLOW << "DecimalFixed型の誤差: " << std::scientific << diff << ANSI_COLOR_RESET << std::endl;
}

void testStringConstruction() {
	printSeparator("文字列コンストラクタテスト");
	
	std::vector<std::string> test_values;
	test_values.push_back("42.42");
	test_values.push_back("3.14159");
	test_values.push_back("0.001");
	test_values.push_back("1000.5");
	test_values.push_back("0.0001");
	
	for (std::vector<std::string>::const_iterator it = test_values.begin(); it != test_values.end(); ++it) {
		const std::string &val = *it;
		DecimalFixed df(val);
		std::cout << "DecimalFixed(\"" << val << "\") = " << df 
				  << " (double: " << std::fixed << std::setprecision(10) << df.toDouble() << ")" << std::endl;
	}
}

void testArithmetic() {
	printSeparator("算術演算テスト");
	
	DecimalFixed a("42.42");
	DecimalFixed b("3.14");
	
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "a + b = " << (a + b) << std::endl;
	std::cout << "a - b = " << (a - b) << std::endl;
	std::cout << "a * b = " << (a * b) << std::endl;
	std::cout << "a / b = " << (a / b) << std::endl;
}

void testComparison() {
	printSeparator("比較演算テスト");
	
	DecimalFixed a("42.42");
	DecimalFixed b("42.42");
	DecimalFixed c("3.14");
	
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "a == b: " << (a == b ? "true" : "false") << std::endl;
	std::cout << "a != c: " << (a != c ? "true" : "false") << std::endl;
	std::cout << "a > c: " << (a > c ? "true" : "false") << std::endl;
	std::cout << "c < a: " << (c < a ? "true" : "false") << std::endl;
}

void testInternalRepresentation() {
	printSeparator("内部表現の詳細");
	
	DecimalFixed df("42.42");
	int raw = df.getRawBits();
	
	std::cout << "DecimalFixed(\"42.42\")の内部表現:" << std::endl;
	std::cout << "  Raw value: " << raw << " (0x" << std::hex << raw << std::dec << ")" << std::endl;
	std::cout << "  Binary: " << std::bitset<32>(raw) << std::endl;
	
	// 手動でビットを分析
	int mantissa = (raw >> 8) & 0xFFFFFF;  // 上位24ビット
	int exponent_raw = raw & 0xFF;         // 下位8ビット
	int exponent = (exponent_raw >= 128) ? exponent_raw - 256 : exponent_raw; // 符号付き変換
	
	std::cout << "  仮数部 (上位24ビット): " << mantissa << std::endl;
	std::cout << "  指数部 (下位8ビット): " << exponent << std::endl;
	std::cout << "  値の検証: " << mantissa << " × 10^(" << exponent << ") = " 
			  << static_cast<double>(mantissa) * std::pow(10.0, exponent) << std::endl;
}

void testEdgeCases() {
	printSeparator("エッジケーステスト");
	
	// 非常に小さい数
	DecimalFixed small("0.0001");
	std::cout << "小さい数 (0.0001): " << small << std::endl;
	
	// 大きい数
	DecimalFixed large("999999.99");
	std::cout << "大きい数 (999999.99): " << large << std::endl;
	
	// 整数
	DecimalFixed integer("42");
	std::cout << "整数 (42): " << integer << std::endl;
	
	// ゼロ
	DecimalFixed zero("0");
	std::cout << "ゼロ (0): " << zero << std::endl;
}

int main() {
	std::cout << ANSI_COLOR_MAGENTA << 
	"===================================================\n" <<
	"  DecimalFixed クラステストプログラム\n" <<
	"  10進ベース固定小数点型の実証\n" <<
	"===================================================" 
	<< ANSI_COLOR_RESET << std::endl;
	
	try {
		testPrecision();
		testStringConstruction();
		testArithmetic();
		testComparison();
		testInternalRepresentation();
		testEdgeCases();
		
		std::cout << "\n" << ANSI_COLOR_GREEN << "全てのテストが完了しました！" << ANSI_COLOR_RESET << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << ANSI_COLOR_RED << "エラーが発生しました: " << e.what() << ANSI_COLOR_RESET << std::endl;
		return 1;
	}
	
	return 0;
}
