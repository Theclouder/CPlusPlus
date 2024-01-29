/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:46:27 by vduchi            #+#    #+#             */
/*   Updated: 2024/01/29 14:46:27 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe & rhs)
{
	*this = rhs;
}

PmergeMe& PmergeMe::operator=(const PmergeMe & rhs)
{
	this->_v = rhs._v;
	this->_l = rhs._l;
	return *this;
}

PmergeMe::~PmergeMe() {}

