/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:18 by torinoue          #+#    #+#             */
/*   Updated: 2025/08/13 18:35:59 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include "AnsiColor.hpp"

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed & other);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		Fixed &operator=(const Fixed &src);

	private:
		int _value;
		static const int _fractionalBits;
};

#endif
