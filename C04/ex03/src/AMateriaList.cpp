/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateriaList.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:11:15 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/19 16:18:48 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateriaList.hpp"

AMateriaList::AMateriaList()
{
	this->_mat = NULL;
	this->_next = NULL;
}

AMateriaList::AMateriaList(AMateriaList const & other)
{
	*this = other;
}

AMateriaList& AMateriaList::operator=(AMateriaList const & other)
{
	this->_mat = other->_mat;
	this->_bef = other->_bef;
	this->_next = other->_next;
}

AMateriaList::~AMateriaList()
{
	this->_mat = NULL;
	this->_bef = NULL;
	this->_next = NULL;
}
