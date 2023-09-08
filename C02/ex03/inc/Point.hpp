/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:39:24 by vduchi            #+#    #+#             */
/*   Updated: 2023/09/08 16:03:33 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H__
#define POINT_H__

#include "Fixed.hpp"

class Point : Fixed
{
public:
	Point(void);
	Point(const Point &cpy);
	Point(const float x, const float y);
	~Point(void);

	Point &operator=(const Point &cpy);

private:
	const Fixed _x;
	const Fixed _y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif