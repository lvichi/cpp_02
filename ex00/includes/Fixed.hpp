/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:49:44 by lvichi            #+#    #+#             */
/*   Updated: 2024/12/04 18:49:44 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma	once

#include <iostream>

class Fixed {
	private:
		int					_number;
		static const int	_fraction_bits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &original);
		Fixed	&operator=(const Fixed &original);
		int		getRawBits() const;
		void	setRawBits(const int raw);
};
