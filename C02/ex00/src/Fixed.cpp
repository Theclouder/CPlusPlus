/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:19:44 by vduchi            #+#    #+#             */
/*   Updated: 2023/09/22 10:49:21 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed(void)
{
	this->_value = 0;
	std::cout << "Default constructor called!" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called!" << std::endl;
}

Fixed::Fixed(Fixed &cpy)
{
	std::cout << "Copy constructor called!" << std::endl;
	*this = cpy;
}

Fixed &Fixed::operator=(const Fixed &cpy)
{
	this->setRawBits(cpy.getRawBits());
	std::cout << "Operator overloading called!" << std::endl;
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits function called!" << std::endl;
	return _value;
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}
