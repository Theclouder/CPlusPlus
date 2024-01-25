/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:02:09 by vduchi            #+#    #+#             */
/*   Updated: 2024/01/25 12:21:10 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template <typename T> void swap(T &a, T &b)
{
	T c = a;
	a = b;
	b = c;
}

template <typename T> T min(T &a, T &b)
{
	if (a < b)
		return a;
	return b;
}

template <typename T> T max(T &a, T &b)
{
	if (a < b)
		return b;
	return a;
}

#endif
