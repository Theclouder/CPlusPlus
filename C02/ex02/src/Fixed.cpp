/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:19:44 by vduchi            #+#    #+#             */
/*   Updated: 2023/09/08 15:30:17 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

float floatToRaw(float value, int bits) { return std::roundf(value * (1 << bits)); }

Fixed::Fixed(void) { this->_value = 0; }
Fixed::Fixed(const Fixed &cpy) { this->setRawBits(cpy.getRawBits()); }
Fixed::Fixed(const int par) { this->_value = (par << Fixed::_bits); }
Fixed::Fixed(const float par) { this->_value = floatToRaw(par, this->_bits); }
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

Fixed Fixed::operator+(const Fixed &other)
{
	Fixed res;
	res.setRawBits(this->getRawBits() + other.getRawBits());
	return res;
}

Fixed Fixed::operator-(const Fixed &other)
{
	Fixed res;
	res.setRawBits(this->getRawBits() - other.getRawBits());
	return res;
}

Fixed Fixed::operator*(const Fixed &other)
{
	Fixed res;
	res.setRawBits(floatToRaw(this->toFloat() * other.toFloat(), this->_bits));
	return res;
}

Fixed Fixed::operator/(const Fixed &other)
{
	Fixed res;
	res.setRawBits(floatToRaw(this->toFloat() / other.toFloat(), this->_bits));
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

int Fixed::toInt(void) const { return this->_value >> Fixed::_bits; }
float Fixed::toFloat(void) const { return (float)this->_value / (float)(1 << Fixed::_bits); }

Fixed &Fixed::min(Fixed &first, Fixed &second) { return first.getRawBits() >= second.getRawBits() ? second : first; }
Fixed &Fixed::max(Fixed &first, Fixed &second) { return first.getRawBits() >= second.getRawBits() ? first : second; }
const Fixed &Fixed::min(const Fixed &first, const Fixed &second) { return first.getRawBits() >= second.getRawBits() ? second : first; }
const Fixed &Fixed::max(const Fixed &first, const Fixed &second) { return first.getRawBits() >= second.getRawBits() ? first : second; }
