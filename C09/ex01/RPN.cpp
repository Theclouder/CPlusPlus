/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:45:55 by vduchi            #+#    #+#             */
/*   Updated: 2024/01/29 11:19:44 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN & rhs)
{
	*this = rhs;
}

RPN& RPN::operator=(const RPN & rhs)
{
	this->_stack = rhs._stack;
	return *this;
}

RPN::~RPN() {}

int RPN::popStack()
{
	int val = this->_stack.top();
	this->_stack.pop();
	return val;
}

void RPN::pushStack(int val)
{
	this->_stack.push(val);
}

