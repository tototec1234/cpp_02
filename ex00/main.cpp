/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:06 by torinoue          #+#    #+#             */
/*   Updated: 2025/08/13 18:35:59 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AnsiColor.hpp"
#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	{
		std::cout << ANSI_COLOR_CYAN << "\n=== 元の課題書テスト ===" << ANSI_COLOR_RESET << std::endl;
		Fixed a;
		Fixed b( a );
		Fixed c;

		std::cerr << ANSI_COLOR_BLUE << "Command: c = b;" << ANSI_COLOR_RESET << std::endl;

		c = b;
		std::cout << a.getRawBits() << std::endl;
		std::cout << b.getRawBits() << std::endl;
		std::cout << c.getRawBits() << std::endl;
	}
	{
		std::cout << ANSI_COLOR_CYAN << "\n=== const型のテスト ===" << ANSI_COLOR_RESET << std::endl;
		Fixed a;
		const Fixed b( a );
		Fixed c;
		const Fixed d( c );

		std::cerr << ANSI_COLOR_BLUE << "Command: c = b;" << ANSI_COLOR_RESET << std::endl;

		c = b;
		std::cout << a.getRawBits() << std::endl;
		std::cout << b.getRawBits() << std::endl;
		std::cout << c.getRawBits() << std::endl;
		std::cout << d.getRawBits() << std::endl;
	}
	return 0;
}

/*
	{
		std::cout << ANSI_COLOR_CYAN << "\n=== const型のテスト ===" << ANSI_COLOR_RESET << std::endl;
		Fixed a;
		const Fixed b( a );
		constFixed c;
		const Fixed d( c );

		std::cerr << ANSI_COLOR_BLUE << "Command: c = b;" << ANSI_COLOR_RESET << std::endl;

		b = a;
		std::cout << a.getRawBits() << std::endl;
		std::cout << b.getRawBits() << std::endl;
		std::cout << c.getRawBits() << std::endl;
		std::cout << d.getRawBits() << std::endl;
	}
*/