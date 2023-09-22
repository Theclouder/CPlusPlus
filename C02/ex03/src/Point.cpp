/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:40:52 by vduchi            #+#    #+#             */
/*   Updated: 2023/09/22 18:05:50 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {}
Point::Point(const Point &cpy) : _x(cpy.getX()), _y(cpy.getY()) {}
Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y)) {}
Point::Point(const Fixed x, const Fixed y) : _x(x), _y(y) {}
Point::~Point(void) {}

Point &Point::operator=(const Point &cpy)
{
	(void)cpy;
	return (*this);
}

const Fixed Point::getX(void) const
{
	return this->_x;
}

const Fixed Point::getY(void) const
{
	return this->_y;
}
