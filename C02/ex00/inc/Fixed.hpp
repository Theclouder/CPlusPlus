/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:13:04 by vduchi            #+#    #+#             */
/*   Updated: 2023/09/05 12:28:24 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H__
#define FIXED_H__
#include <iostream>

class Fixed
{
public:
	Fixed(void);
	~Fixed(void);
	Fixed(Fixed &cpy);
	Fixed &operator=(const Fixed &cpy);

	int getRawBits(void) const;
	void setRawBits(int const raw);

private:
	int _value;
	static int bits;
};

static int bits = 8;

#endif
