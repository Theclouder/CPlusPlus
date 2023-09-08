/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:40:52 by vduchi            #+#    #+#             */
/*   Updated: 2023/09/08 16:02:30 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {}
Point::Point(const Point &cpy) : _x(cpy._x.getRawBits()), _y(cpy._y.getRawBits()) {}
Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y)) {}
Point::~Point(void) {}

Point &Point::operator=(const Point &cpy)
{
	Point newPoint(cpy);
	return (newPoint);
}