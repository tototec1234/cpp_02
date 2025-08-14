/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:18 by torinoue          #+#    #+#             */
/*   Updated: 2025/08/13 19:10:39 by toruinoue        ###   ########.fr       */
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
		Fixed(const Fixed & other);
		~Fixed(void);
		Fixed &operator=(const Fixed &src);

		int getRawBits( void ) const;
		void setRawBits( int const raw );

	private:
		int _value;
		static const int _fractionalBits;
};

#endif
