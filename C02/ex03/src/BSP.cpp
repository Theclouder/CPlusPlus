/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSP.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:02:54 by vduchi            #+#    #+#             */
/*   Updated: 2023/09/22 18:28:59 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed area(Point p1, Point p2, Point p3)
{
	return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed f1, f2, f3;
	bool isNeg, isPos;

	f1 = area(point, a, b);
	f2 = area(point, b, c);
	f3 = area(point, c, a);

	isNeg = (f1 < 0) || (f2 < 0) || (f3 < 0);
	isPos = (f1 > 0) || (f2 > 0) || (f3 > 0);
	if (f1 == 0 || f2 == 0 || f3 == 0)
		return (0);
	return (!(isNeg && isPos));
}
