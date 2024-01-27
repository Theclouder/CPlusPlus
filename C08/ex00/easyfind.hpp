/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:02:19 by vduchi            #+#    #+#             */
/*   Updated: 2024/01/26 18:38:20 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <list>
#include <array>
#include <vector>
#include <sstream>
#include <iostream>
#include "Colors.hpp"

class NotFoundException : public std::out_of_range
{
	public:
		NotFoundException() : std::out_of_range("Out of range!") {};
};

template <typename T> int easyfind(T vec, int n)
{
	typename T::iterator it;
	for (it = vec.begin(); it != vec.end(); it++)
		if (*it == n)
			return *it;
	throw NotFoundException();
}

#endif
