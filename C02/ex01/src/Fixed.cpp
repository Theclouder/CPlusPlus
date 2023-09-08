/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:19:44 by vduchi            #+#    #+#             */
/*   Updated: 2023/09/06 18:48:33 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

Fixed::Fixed(void)
{
	this->_value = 0;
	std::cout << "Default constructor called!" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called!" << std::endl;
}

Fixed::Fixed(const Fixed &cpy)
{
	this->setRawBits(cpy.getRawBits());
	std::cout << "Copy constructor called!" << std::endl;
}

Fixed::Fixed(const int par)
{
	this->_value = (par << Fixed::_bits);
	std::cout << "Int constructor called!" << std::endl;
}

Fixed::Fixed(const float par)
{
	this->_value = std::roundf(par * (1 << Fixed::_bits));
	std::cout << "Float constructor called!" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &cpy)
{
	this->setRawBits(cpy.getRawBits());
	std::cout << "Operator = overloading called!" << std::endl;
	return (*this);
}

std::ostream &operator<<(std::ostream &s, const Fixed &cpy)
{
	s << cpy.toFloat();
	return s;
}

int Fixed::getRawBits(void) const { return this->_value; }

void Fixed::setRawBits(int const raw) { this->_value = raw; }

int Fixed::toInt(void) const
{
	return this->_value >> Fixed::_bits;
}

float Fixed::toFloat(void) const
{
	float res = (float)this->_value / (float)(1 << Fixed::_bits);
	return res;
}
