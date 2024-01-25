/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:02:09 by vduchi            #+#    #+#             */
/*   Updated: 2024/01/25 15:27:21 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T, typename U, typename F> void iter(T *addr, U len, F (*func)(T&))
{
	for (U i = 0; i < len; i++)
		func(addr[i]);
}

#endif
