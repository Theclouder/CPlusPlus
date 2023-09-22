/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:19:44 by vduchi            #+#    #+#             */
/*   Updated: 2023/09/22 18:53:28 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

Fixed::Fixed(void) { this->_value = 0; }
Fixed::Fixed(const Fixed &cpy) { *this = cpy; }
Fixed::Fixed(const int par) { this->_value = (par << Fixed::_bits); }
Fixed::Fixed(const float par) { this->_value = int(roundf(par * (1 << this->getFractBits()))); }
Fixed::~Fixed(void) {}

Fixed &Fixed::operator=(const Fixed &cpy)
{
	this->setRawBits(cpy.getRawBits());
	return (*this);
}

int Fixed::operator==(const Fixed &other) { return this->getRawBits() == other.getRawBits() ? 1 : 0; }
int Fixed::operator!=(const Fixed &other) { return this->getRawBits() != other.getRawBits() ? 1 : 0; }
int Fixed::operator>(const Fixed &other) { return this->getRawBits() > other.getRawBits() ? 1 : 0; }
int Fixed::operator<(const Fixed &other) { return this->getRawBits() < other.getRawBits() ? 1 : 0; }
int Fixed::operator>=(const Fixed &other) { return this->getRawBits() >= other.getRawBits() ? 1 : 0; }
int Fixed::operator<=(const Fixed &other) { return this->getRawBits() <= other.getRawBits() ? 1 : 0; }

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed res;
	res.setRawBits(this->getRawBits() + other.getRawBits());
	return res;
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed res;
	res.setRawBits(this->getRawBits() - other.getRawBits());
	return res;
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed res(this->toFloat() * other.toFloat());
	return res;
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed res(this->toFloat() / other.toFloat());
	return res;
}

Fixed &Fixed::operator++()
{
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}

Fixed &Fixed::operator--()
{
	this->setRawBits(this->getRawBits() - 1);
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp;
	temp.setRawBits(this->getRawBits());
	this->setRawBits(this->getRawBits() + 1);
	return temp;
}

Fixed Fixed::operator--(int)
{
	Fixed temp;
	temp.setRawBits(this->getRawBits());
	this->setRawBits(this->getRawBits() - 1);
	return temp;
}

std::ostream &operator<<(std::ostream &s, const Fixed &cpy)
{
	s << cpy.toFloat();
	return s;
}

int Fixed::getRawBits(void) const { return this->_value; }
int Fixed::getFractBits(void) const { return this->_bits; }
void Fixed::setRawBits(int const raw) { this->_value = raw; }

int Fixed::toInt(void) const { return this->_value >> this->getFractBits(); }
float Fixed::toFloat(void) const { return (float(this->_value / float(1 << this->_bits))); }

Fixed &Fixed::min(Fixed &first, Fixed &second) { return first.getRawBits() >= second.getRawBits() ? second : first; }
Fixed &Fixed::max(Fixed &first, Fixed &second) { return first.getRawBits() >= second.getRawBits() ? first : second; }
const Fixed &Fixed::min(const Fixed &first, const Fixed &second) { return first.getRawBits() >= second.getRawBits() ? second : first; }
const Fixed &Fixed::max(const Fixed &first, const Fixed &second) { return first.getRawBits() >= second.getRawBits() ? first : second; }
