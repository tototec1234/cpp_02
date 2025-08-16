/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DecimalFixed.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 xx:xx:xx by toruinoue          #+#    #+#             */
/*   Updated: 2025/01/27 xx:xx:xx by toruinoue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DECIMALFIXED_HPP
# define DECIMALFIXED_HPP

# include <iostream>
# include <string>
# include <cmath>
# include "AnsiColor.hpp"

/*
 * DecimalFixed class: 10進ベースの固定小数点型
 * 
 * 内部表現: 32ビット整数
 * ┌─────────────────────────┬────────────────┐
 * │     仮数部 m (24bit)     │ 指数部 e (8bit) │
 * └─────────────────────────┴────────────────┘
 * 
 * 値 = m × 10^e
 * 
 * 例: 42.42 → m=4242, e=-2 (4242 × 10^(-2))
 */
class DecimalFixed
{
	public:
		// コンストラクタ・デストラクタ
		DecimalFixed(void);
		DecimalFixed(const std::string &decimal_string);
		DecimalFixed(double value);
		DecimalFixed(const DecimalFixed &src);
		~DecimalFixed(void);

		// 代入演算子
		DecimalFixed &operator=(const DecimalFixed &src);

		// アクセサ
		int getRawBits(void) const;
		void setRawBits(int raw);

		// 変換関数
		double toDouble(void) const;
		std::string toString(void) const;

		// 比較演算子
		bool operator==(const DecimalFixed &other) const;
		bool operator!=(const DecimalFixed &other) const;
		bool operator<(const DecimalFixed &other) const;
		bool operator<=(const DecimalFixed &other) const;
		bool operator>(const DecimalFixed &other) const;
		bool operator>=(const DecimalFixed &other) const;

		// 算術演算子
		DecimalFixed operator+(const DecimalFixed &other) const;
		DecimalFixed operator-(const DecimalFixed &other) const;
		DecimalFixed operator*(const DecimalFixed &other) const;
		DecimalFixed operator/(const DecimalFixed &other) const;

	private:
		int _value;  // 上位24ビット: 仮数部、下位8ビット: 指数部

		// 定数
		static const int MANTISSA_BITS = 24;
		static const int EXPONENT_BITS = 8;
		static const int MANTISSA_MASK = 0xFFFFFF00;  // 上位24ビットマスク
		static const int EXPONENT_MASK = 0x000000FF;  // 下位8ビットマスク
		static const int MAX_MANTISSA = (1 << MANTISSA_BITS) - 1;  // 16777215
		static const int MIN_EXPONENT = -128;
		static const int MAX_EXPONENT = 127;

		// ヘルパー関数
		int getMantissa(void) const;
		int getExponent(void) const;
		void setMantissaAndExponent(long long mantissa, int exponent);
		void normalize(void);
		long long power10(int exp) const;
		DecimalFixed createFromMantissaAndExponent(long long mantissa, int exponent) const;
};

// 出力演算子
std::ostream &operator<<(std::ostream &out, const DecimalFixed &fixed);

#endif
