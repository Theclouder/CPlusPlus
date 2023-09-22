/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:19:44 by vduchi            #+#    #+#             */
/*   Updated: 2023/09/22 18:54:34 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed(void) { this->_value = 0; }
Fixed::Fixed(const Fixed &cpy) { *this = cpy; }
Fixed::Fixed(const int par) { this->_value = (par << Fixed::_bits); }
Fixed::Fixed(const float par) { this->_value = int(roundf(par * (1 << this->_bits))); }
Fixed::~Fixed(void) {}

Fixed &Fixed::operator=(const Fixed &cpy)
{
	this->setRawBits(cpy.getRawBits());
	return (*this);
}

std::ostream &operator<<(std::ostream &s, const Fixed &cpy)
{
	s << cpy.toFloat();
	return s;
}

int Fixed::getRawBits(void) const { return this->_value; }
void Fixed::setRawBits(int const raw) { this->_value = raw; }

int Fixed::toInt(void) const { return this->_value >> this->_bits; }
float Fixed::toFloat(void) const { return (float(this->_value / float(1 << this->_bits))); }
