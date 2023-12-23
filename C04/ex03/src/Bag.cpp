/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bag.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 20:59:19 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/23 21:17:03 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bag.hpp"

Bag::Bag()
{
	this->_size = 0;
	this->_last = NULL;
}

Bag::Bag(Bag const & other)
{
	*this = other;
}

Bag& Bag::operator=(Bag const & other)
{
	this->_size = other._size;
	this->_last = other._last;
	return *this;
}

Bag::~Bag()
{
	if (this->_last == NULL)
		return ;
	AMateriaNode* tmp = this->_last;
	AMateriaNode* bef = this->_last->getBef();
	while (tmp != NULL)
	{
		delete tmp;
		tmp = bef;
		if (bef != NULL)
			bef = tmp->getBef();
	}
}

void Bag::addNode(AMateria * mat)
{
	AMateriaNode* node = new AMateriaNode(mat);
	if (this->_last == NULL)
		this->_last = node;
	else
	{
		this->_last->setNext(node);
		node->setBef(this->_last);
		this->_last = node;
	}
}
