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

// Constructors and destructor in canonical form
Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	this->_number = 0;
}

Fixed::Fixed(const Fixed &original) {
	std::cout << "Copy constructor called" << std::endl;
	*this = original;
}

Fixed	&Fixed::operator=(const Fixed &original) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &original) {
		this->_number = original._number;
	}
	return (*this);
}

Fixed::Fixed(const int number) {
	std::cout << "Int constructor called" << std::endl;
	this->_number = number * (1 << _fraction_bits);
}

Fixed::Fixed(const float number) {
	std::cout << "Float constructor called" << std::endl;
	this->_number = int(number * (1 << _fraction_bits) + 0.5);
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

// Comparison operators
bool	Fixed::operator>(const Fixed &fixed_number) const {
	return this->_number > fixed_number._number;
}

bool	Fixed::operator<(const Fixed &fixed_number) const {
	return this->_number < fixed_number._number;
}

bool	Fixed::operator>=(const Fixed &fixed_number) const {
	return this->_number >= fixed_number._number;
}

bool	Fixed::operator<=(const Fixed &fixed_number) const {
	return this->_number <= fixed_number._number;
}

bool	Fixed::operator==(const Fixed &fixed_number) const {
	return this->_number == fixed_number._number;
}

bool	Fixed::operator!=(const Fixed &fixed_number) const {
	return this->_number != fixed_number._number;
}

// Arithmetic operators
Fixed	Fixed::operator+(const Fixed &fixed_number) const {
	Fixed	result;

	result._number = this->_number + fixed_number._number;
	return result;
}

Fixed	Fixed::operator-(const Fixed &fixed_number) const {
	Fixed	result;

	result._number = this->_number - fixed_number._number;
	return result;
}

Fixed	Fixed::operator*(const Fixed &fixed_number) const {
	Fixed	result;

	result._number = (this->_number * fixed_number._number) >> _fraction_bits;
	return result;
}

Fixed	Fixed::operator/(const Fixed &fixed_number) const {
	Fixed	result;

	result._number = (this->_number << _fraction_bits) / fixed_number._number;
	return result;
}

// Increment/Decrement operators
Fixed	&Fixed::operator++() {
	this->_number++;
	return *this;
}

Fixed 	Fixed::operator++(int) {
	Fixed	tmp(*this);

	this->_number++;
	return tmp;
}

Fixed	&Fixed::operator--() {
	this->_number--;
	return *this;
}

Fixed 	Fixed::operator--(int) {
	Fixed	tmp(*this);

	this->_number--;
	return tmp;
}

// Methods
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

// Static methods
Fixed		&Fixed::min(Fixed &left_fixed_number, Fixed &right_fixed_number) {
	if (left_fixed_number < right_fixed_number)
		return left_fixed_number;
	return right_fixed_number;
}

const Fixed	&Fixed::min(const Fixed &left_fixed_number, const Fixed &right_fixed_number) {
	if (left_fixed_number < right_fixed_number)
		return left_fixed_number;
	return right_fixed_number;
}

Fixed		&Fixed::max(Fixed &left_fixed_number, Fixed &right_fixed_number) {
	if (left_fixed_number > right_fixed_number)
		return left_fixed_number;
	return right_fixed_number;
}

const Fixed	&Fixed::max(const Fixed &left_fixed_number, const Fixed &right_fixed_number) {
	if (left_fixed_number > right_fixed_number)
		return left_fixed_number;
	return right_fixed_number;
}

// Output stream operator
std::ostream	&operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return (out);
}
