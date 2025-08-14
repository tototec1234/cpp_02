/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:18 by torinoue          #+#    #+#             */
/*   Updated: 2025/08/13 19:29:18 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include "AnsiColor.hpp"

class Fixed
{
	public:
		Fixed(void);
		Fixed(const int integer);
		Fixed(const float floatingPointNumber);
		Fixed(const Fixed & src);
		~Fixed(void);
		Fixed &operator=(const Fixed &src);

		int		getRawBits( void ) const;
		void 	setRawBits( int const raw );
		// float	toFloat(void) ;
		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int _value;
		static const int _fractionalBits;
};


//	And add the following function to the Fixed class files:
// An overload of the insertion («) operator that inserts a floating-point representation
// of the fixed-point number into the output stream object passed as a parameter.
// std::ostream &operator<<(std::ostream &str,  Fixed &fixed);
std::ostream &operator<<(std::ostream &str, const Fixed fixed);
// std::ostream &operator<<(std::ostream &str, const Fixed &fixed);

#endif
