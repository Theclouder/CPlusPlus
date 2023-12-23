/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateriaNode.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:11:15 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/23 21:02:13 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateriaNode.hpp"

AMateriaNode::AMateriaNode()
{
	this->_mat = NULL;
	this->_bef = NULL;
	this->_next = NULL;
}

AMateriaNode::AMateriaNode(AMateria * mat)
{
	this->_mat = mat;
	this->_bef = NULL;
	this->_next = NULL;
}

AMateriaNode::AMateriaNode(AMateriaNode const & other)
{
	*this = other;
}

AMateriaNode& AMateriaNode::operator=(AMateriaNode const & other)
{
	if (this != &other)
	{
		this->_mat = other._mat->clone();
		this->_bef = other._bef;
		this->_next = other._next;
	}
	return *this;
}

AMateriaNode::~AMateriaNode()
{
	if (this->_mat != NULL)
		delete this->_mat;
}

void AMateriaNode::setMat(AMateria* mat)
{
	this->_mat = mat;
}

void AMateriaNode::setBef(AMateriaNode* bef)
{
	this->_bef = bef;
}

void AMateriaNode::setNext(AMateriaNode* next)
{
	this->_next = next;
}

AMateria* AMateriaNode::getMat() const
{
	return this->_mat;
}

AMateriaNode* AMateriaNode::getBef() const
{
	return this->_bef;
}

AMateriaNode* AMateriaNode::getNext() const
{
	return this->_next;
}
