/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bag.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 20:59:19 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/22 22:00:04 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bag.hpp"

Bag::Bag()
{
	this->_size = 0;
	this->_first = NULL;
	this->_last = NULL;
}

Bag::Bag(Bag const & other)
{
	*this = other;
}

Bag& Bag::operator=(Bag const & other)
{
	this->_size = other->_size;
	this->_first = other->_first;
	this->_last = this->_last;
	return *this;
}

Bag::~Bag()
{
	this->clearList();
}
