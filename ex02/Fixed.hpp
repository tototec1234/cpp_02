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
		
	// Public Methods
		/* Getters and setters */
		int		getRawBits( void ) const;
		void 	setRawBits( int const raw );
		
		/* Conversion functions */
		float	toFloat(void) const;
		int		toInt(void) const;

		/* Static member functions */
		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);


	// Overloaded Operators
		/* Assignment operator */
		Fixed &operator=(const Fixed &src);

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
		/* The 4 increment/decrement (pre-increment and post-increment, pre-decrement and
post-decrement) operators, which will increase or decrease the fixed-point value by
the smallest representable ϵ, such that 1 + ϵ > 1. */
		Fixed	&operator ++(void);
		Fixed	&operator --(void);
		Fixed	operator ++(int);
		Fixed	operator --(int);

	
	private:
		int _value;
		static const int _fractionalBits;
};


std::ostream &operator <<(std::ostream &outputStream, const Fixed &fixed);
#endif

/*
--a;  // コンパイラ → operator--(void) を呼び出す
a--;  // コンパイラ → operator--(int) を呼び出す

*/