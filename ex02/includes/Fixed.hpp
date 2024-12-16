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
	    // Constructors and destructor in canonical form
		Fixed();
		Fixed(const Fixed &original);
		Fixed(const int number);
		Fixed(const float number);
		Fixed	&operator=(const Fixed &original);
		~Fixed();

		// Comparison operators
		bool operator>(const Fixed &fixed_number) const;
		bool operator<(const Fixed &fixed_number) const;
		bool operator>=(const Fixed &fixed_number) const;
		bool operator<=(const Fixed &fixed_number) const;
		bool operator==(const Fixed &fixed_number) const;
		bool operator!=(const Fixed &fixed_number) const;

		// Arithmetic operators
		Fixed operator+(const Fixed &fixed_number) const;
		Fixed operator-(const Fixed &fixed_number) const;
		Fixed operator*(const Fixed &fixed_number) const;
		Fixed operator/(const Fixed &fixed_number) const;

		// Increment/Decrement operators
		Fixed &operator++();       // Pre-increment
		Fixed operator++(int);     // Post-increment
		Fixed &operator--();       // Pre-decrement
		Fixed operator--(int);     // Post-decrement

		// Methods
		int		getRawBits() const;
		void	setRawBits(const int raw);
		float	toFloat() const;
		int		toInt() const;

		// Static methods
		static Fixed		&min(Fixed &left_fixed_number, Fixed &right_fixed_number);
		static const Fixed	&min(const Fixed &left_fixed_number, const Fixed &right_fixed_number);
		static Fixed 		&max(Fixed &left_fixed_number, Fixed &right_fixed_number);
		static const Fixed 	&max(const Fixed &left_fixed_number, const Fixed &right_fixed_number);
};

// Output stream operator
std::ostream	&operator<<(std::ostream &out, const Fixed &fixed);
