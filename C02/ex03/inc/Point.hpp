/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:39:24 by vduchi            #+#    #+#             */
/*   Updated: 2023/09/22 17:48:07 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H__
#define POINT_H__

#include "Fixed.hpp"

class Point
{
public:
	Point(void);
	Point(const Point &cpy);
	Point(const float x, const float y);
	Point(const Fixed x, const Fixed y);
	~Point(void);

	Point &operator=(const Point &cpy);
	const Fixed getX() const;
	const Fixed getY() const;

private:
	const Fixed _x;
	const Fixed _y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
