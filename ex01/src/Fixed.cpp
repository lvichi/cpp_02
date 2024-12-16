/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:00:32 by lvichi            #+#    #+#             */
/*   Updated: 2024/12/04 19:00:32 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	this->_number = 0;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &original) {
	std::cout << "Copy constructor called" << std::endl;
	*this = original;
}

Fixed::Fixed(const int number) {
	std::cout << "Int constructor called" << std::endl;
	this->_number = number * (1 << _fraction_bits);
}

Fixed::Fixed(const float number) {
	std::cout << "Float constructor called" << std::endl;
	this->_number = int(number) * (1 << _fraction_bits);
	this->_number += (number - int(number)) * (1 << _fraction_bits);
}

Fixed	&Fixed::operator=(const Fixed &original) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &original) {
		this->_number = original._number;
	}
	return (*this);
}

int		Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_number);
}

void	Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_number = raw;
}

float	Fixed::toFloat() const {
	int		integer_part;
	int		fraction_part;
	float	float_number;

	integer_part = this->_number >> this->_fraction_bits;
	fraction_part = this->_number & ((1 << this->_fraction_bits) - 1);
	float_number = fraction_part / float(1 << this->_fraction_bits);

	return (float(integer_part) + float_number);
}

int		Fixed::toInt() const {
	return this->_number >> _fraction_bits;
}

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return (out);
}
