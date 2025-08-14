/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:18 by torinoue          #+#    #+#             */
/*   Updated: 2025/08/14 15:10:43 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include "AnsiColor.hpp"

class Fixed
{
	public:
		/* Contstructors & Destructors */
		Fixed(void);
		Fixed(const int integer);
		Fixed(const float floatingPointNumber);
		Fixed(const Fixed & src);
		~Fixed(void);

		/* Assignment operator */
		Fixed &operator=(const Fixed &src);

		
		/* Getters and setters */
		int		getRawBits( void ) const;
		void 	setRawBits( int const raw );
		
		/* Conversion functions */
		float	toFloat(void) const;
		int		toInt(void) const;

		/* The 6 comparison operators: >, <, >=, <=, ==, and !=. */
		bool	operator >(const Fixed &other) const;
		bool	operator <(const Fixed &other) const;
		bool	operator >=(const Fixed &other) const;
		bool	operator <=(const Fixed &other) const;
		bool	operator ==(const Fixed &other) const;
		bool	operator !=(const Fixed &other) const;
		/* The 4 arithmetic operators: +, -, *, and /. */
		Fixed	operator +(const Fixed &other) const;
		Fixed	operator -(const Fixed &other) const;
		Fixed	operator *(const Fixed &other) const;
		Fixed	operator /(const Fixed &other) const;

				
	private:
		int _value;
		static const int _fractionalBits;
};


std::ostream &operator <<(std::ostream &outputStream, const Fixed &fixed);
#endif
