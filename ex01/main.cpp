/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:06 by torinoue          #+#    #+#             */
/*   Updated: 2025/08/13 19:00:34 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AnsiColor.hpp"
#include <iostream>
#include "Fixed.hpp"

int main( void )
{

	{
		Fixed a;
		/*
		Fixed const b( 10 );
		Fixed const c( 42.42f );
		Fixed const d( b );
		*/
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
	return 0;
}