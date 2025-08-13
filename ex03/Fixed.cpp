/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torinoue <torinoue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:18 by torinoue          #+#    #+#             */
/*   Updated: 2025/08/11 19:54:12 by torinoue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.Hpp"

class Fixed{

	public:
		Fixed();
		Fixed(std::string num);
		Fixed(Fixed & other);
		int getRawBits( void ) const;
		void setRawBits( int const raw );

	private:
		int sisuBu;
		static const syousuBu;
}


