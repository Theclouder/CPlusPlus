/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateriaNode.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:11:15 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/22 21:02:11 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateriaNode.hpp"

AMateriaNode::AMateriaNode()
{
	this->_mat = NULL;
	this->_next = NULL;
}

AMateriaNode::AMateriaNode(AMateriaNode const & other)
{
	*this = other;
}

AMateriaNode& AMateriaNode::operator=(AMateriaNode const & other)
{
	this->_mat = other->_mat;
	this->_bef = other->_bef;
	this->_next = other->_next;
}

AMateriaNode::~AMateriaNode()
{
	this->_mat = NULL;
	this->_bef = NULL;
	this->_next = NULL;
}
