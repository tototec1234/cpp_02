/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DecimalFixed.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 xx:xx:xx by toruinoue          #+#    #+#             */
/*   Updated: 2025/01/27 xx:xx:xx by toruinoue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DecimalFixed.hpp"
#include <sstream>
#include <algorithm>
#include <climits>

// デフォルトコンストラクタ
DecimalFixed::DecimalFixed(void) : _value(0) {
	std::cerr << ANSI_COLOR_YELLOW << "DecimalFixed Default Constructor called" << ANSI_COLOR_RESET << std::endl;
}

// 文字列コンストラクタ (例: "42.42")
DecimalFixed::DecimalFixed(const std::string &decimal_string) {
	std::cerr << ANSI_COLOR_YELLOW << "DecimalFixed String Constructor called with: " << decimal_string << ANSI_COLOR_RESET << std::endl;
	
	size_t dot_pos = decimal_string.find('.');
	if (dot_pos == std::string::npos) {
		// 整数の場合
		long long mantissa = std::stoll(decimal_string);
		setMantissaAndExponent(mantissa, 0);
	} else {
		// 小数の場合
		std::string integer_part = decimal_string.substr(0, dot_pos);
		std::string fractional_part = decimal_string.substr(dot_pos + 1);
		
		// 整数部と小数部を結合
		std::string combined = integer_part + fractional_part;
		long long mantissa = std::stoll(combined);
		int exponent = -static_cast<int>(fractional_part.length());
		
		setMantissaAndExponent(mantissa, exponent);
	}
	normalize();
}

// doubleコンストラクタ
DecimalFixed::DecimalFixed(double value) {
	std::cerr << ANSI_COLOR_YELLOW << "DecimalFixed Double Constructor called with: " << value << ANSI_COLOR_RESET << std::endl;
	
	// doubleを文字列に変換してから処理（精度を保つため）
	std::ostringstream oss;
	oss << std::fixed << value;
	std::string str = oss.str();
	
	// 末尾の0を削除
	str.erase(str.find_last_not_of('0') + 1, std::string::npos);
	if (str.back() == '.') {
		str.pop_back();
	}
	
	*this = DecimalFixed(str);
}

// コピーコンストラクタ
DecimalFixed::DecimalFixed(const DecimalFixed &src) {
	std::cerr << ANSI_COLOR_YELLOW << "DecimalFixed Copy Constructor called" << ANSI_COLOR_RESET << std::endl;
	*this = src;
}

// デストラクタ
DecimalFixed::~DecimalFixed(void) {
	std::cerr << ANSI_COLOR_RED << "DecimalFixed Destructor called" << ANSI_COLOR_RESET << std::endl;
}

// 代入演算子
DecimalFixed &DecimalFixed::operator=(const DecimalFixed &src) {
	std::cout << "DecimalFixed Copy Assignment Operator called" << std::endl;
	if (this != &src) {
		this->_value = src._value;
	}
	return *this;
}

// ヘルパー関数: 仮数部取得
int DecimalFixed::getMantissa(void) const {
	return (_value >> EXPONENT_BITS) & ((1 << MANTISSA_BITS) - 1);
}

// ヘルパー関数: 指数部取得（符号付き）
int DecimalFixed::getExponent(void) const {
	int exp = _value & EXPONENT_MASK;
	// 8ビット符号付き整数として変換
	if (exp >= 128) {
		exp -= 256;
	}
	return exp;
}

// ヘルパー関数: 仮数部と指数部を設定
void DecimalFixed::setMantissaAndExponent(long long mantissa, int exponent) {
	// 仮数部の範囲チェック
	if (mantissa > MAX_MANTISSA) {
		std::cerr << ANSI_COLOR_RED << "Warning: Mantissa " << mantissa 
				  << " exceeds maximum " << MAX_MANTISSA << ANSI_COLOR_RESET << std::endl;
		mantissa = MAX_MANTISSA;
	}
	
	// 指数部の範囲チェック
	if (exponent < MIN_EXPONENT) {
		std::cerr << ANSI_COLOR_RED << "Warning: Exponent " << exponent 
				  << " is below minimum " << MIN_EXPONENT << ANSI_COLOR_RESET << std::endl;
		exponent = MIN_EXPONENT;
	} else if (exponent > MAX_EXPONENT) {
		std::cerr << ANSI_COLOR_RED << "Warning: Exponent " << exponent 
				  << " exceeds maximum " << MAX_EXPONENT << ANSI_COLOR_RESET << std::endl;
		exponent = MAX_EXPONENT;
	}
	
	// 8ビット符号付き整数として格納
	unsigned int exp_bits = static_cast<unsigned int>(exponent) & EXPONENT_MASK;
	
	_value = (static_cast<int>(mantissa) << EXPONENT_BITS) | exp_bits;
}

// ヘルパー関数: 正規化（仮数部が範囲外の場合、指数部を調整）
void DecimalFixed::normalize(void) {
	long long mantissa = getMantissa();
	int exponent = getExponent();
	
	// 仮数部が大きすぎる場合
	while (mantissa > MAX_MANTISSA && exponent < MAX_EXPONENT) {
		mantissa /= 10;
		exponent++;
	}
	
	// 仮数部の末尾の0を削除（最適化）
	while (mantissa > 0 && mantissa % 10 == 0 && exponent < MAX_EXPONENT) {
		mantissa /= 10;
		exponent++;
	}
	
	setMantissaAndExponent(mantissa, exponent);
}

// ヘルパー関数: 10の累乗計算
long long DecimalFixed::power10(int exp) const {
	if (exp == 0) return 1;
	if (exp < 0) return 0; // 整数除算では0になる
	
	long long result = 1;
	for (int i = 0; i < exp; i++) {
		result *= 10;
		if (result > LLONG_MAX / 10) {
			return LLONG_MAX; // オーバーフロー防止
		}
	}
	return result;
}

// アクセサ
int DecimalFixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void DecimalFixed::setRawBits(int raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

// 変換関数
double DecimalFixed::toDouble(void) const {
	int mantissa = getMantissa();
	int exponent = getExponent();
	
	if (exponent >= 0) {
		return static_cast<double>(mantissa) * std::pow(10.0, exponent);
	} else {
		return static_cast<double>(mantissa) / std::pow(10.0, -exponent);
	}
}

std::string DecimalFixed::toString(void) const {
	int mantissa = getMantissa();
	int exponent = getExponent();
	
	if (exponent >= 0) {
		// 正の指数: 整数部分
		long long result = static_cast<long long>(mantissa) * power10(exponent);
		return std::to_string(result);
	} else {
		// 負の指数: 小数部分
		std::string mantissa_str = std::to_string(mantissa);
		int decimal_places = -exponent;
		
		if (decimal_places >= static_cast<int>(mantissa_str.length())) {
			// 0.00xxx の形式
			int leading_zeros = decimal_places - mantissa_str.length();
			return "0." + std::string(leading_zeros, '0') + mantissa_str;
		} else {
			// xxx.yyy の形式
			int split_pos = mantissa_str.length() - decimal_places;
			return mantissa_str.substr(0, split_pos) + "." + mantissa_str.substr(split_pos);
		}
	}
}

// 比較演算子
bool DecimalFixed::operator==(const DecimalFixed &other) const {
	return toDouble() == other.toDouble();
}

bool DecimalFixed::operator!=(const DecimalFixed &other) const {
	return !(*this == other);
}

bool DecimalFixed::operator<(const DecimalFixed &other) const {
	return toDouble() < other.toDouble();
}

bool DecimalFixed::operator<=(const DecimalFixed &other) const {
	return toDouble() <= other.toDouble();
}

bool DecimalFixed::operator>(const DecimalFixed &other) const {
	return toDouble() > other.toDouble();
}

bool DecimalFixed::operator>=(const DecimalFixed &other) const {
	return toDouble() >= other.toDouble();
}

// 算術演算子
DecimalFixed DecimalFixed::operator+(const DecimalFixed &other) const {
	return DecimalFixed(this->toDouble() + other.toDouble());
}

DecimalFixed DecimalFixed::operator-(const DecimalFixed &other) const {
	return DecimalFixed(this->toDouble() - other.toDouble());
}

DecimalFixed DecimalFixed::operator*(const DecimalFixed &other) const {
	return DecimalFixed(this->toDouble() * other.toDouble());
}

DecimalFixed DecimalFixed::operator/(const DecimalFixed &other) const {
	if (other.toDouble() == 0.0) {
		std::cerr << ANSI_COLOR_RED << "Error: Division by zero!" << ANSI_COLOR_RESET << std::endl;
		return DecimalFixed();
	}
	return DecimalFixed(this->toDouble() / other.toDouble());
}

// 出力演算子
std::ostream &operator<<(std::ostream &out, const DecimalFixed &fixed) {
	return out << fixed.toString();
}
