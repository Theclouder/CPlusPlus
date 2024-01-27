/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:50:39 by vduchi            #+#    #+#             */
/*   Updated: 2024/01/27 17:43:46 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

Span::Span() : _curr(0), _max(0) {}

Span::Span(const Span & rhs) : _max(rhs._max)
{
	*this = rhs;
}

Span& Span::operator=(const Span & rhs)
{
	this->_curr = rhs._curr;
	const_cast<unsigned int&>(this->_max) = rhs._max;
	std::copy(rhs._list.begin(), rhs._list.end(), std::back_inserter(this->_list));
	return *this;
}

Span::Span(const unsigned int max) : _curr(0), _max(max) { std::cout << CYAN << "Created Span with " << _max << " elements" << RESET << std::endl;}

Span::~Span() {}

void Span::addNumber(int n)
{
	std::cout << YELLOW << "Adding " << n << " to the storage..." << RESET << std::endl;
	if (this->getCurr() == this->getMax())
		throw e_oof;
	this->setCurr(this->getCurr() + 1);
	this->_list.push_back(n);
	std::cout << GREEN << "Added " << n << " successfully!" << RESET << std::endl << std::endl;
}

void Span::setCurr(int n) { this->_curr = n; }
unsigned int Span::getMax() const { return this->_max; }
unsigned int Span::getCurr() const { return this->_curr; }
const char *Span::TooManyElementsException::what() const throw() { return RED "Storage full!" RESET; }
const char *Span::NotEnoughElementsException::what() const throw() { return RED "Not enough numbers!" RESET; }

unsigned int Span::shortestSpan()
{
	unsigned int span = 0;
	if (this->getCurr() < 2)
		throw e_nee;
	std::list<unsigned int>::iterator it1 = this->_list.begin();
	std::list<unsigned int>::iterator it2 = it1;
	++it2;
	span = *it1 > *it2 ? *it1 - *it2 : *it2 - *it1;
	while (it2 != this->_list.end())
	{
		it1 = it2;
		++it2;
		if ((*it1 > *it2 && span > *it1 - *it2) || (*it2 > *it1 && span > *it2 - *it1))
		{
			if (*it1 > *it2)
				span = *it1 - *it2;
			else
				span = *it2 - *it1;
		}
	}
	return span;
}

unsigned int Span::longestSpan()
{
	unsigned int span = 0;
	if (this->getCurr() < 2)
		throw e_nee;
	std::list<unsigned int>::iterator it1 = this->_list.begin();
	std::list<unsigned int>::iterator it2 = it1;
	++it2;
	span = *it1 > *it2 ? *it1 - *it2 : *it2 - *it1;
	while (it2 != this->_list.end())
	{
		it1 = it2;
		++it2;
		if ((*it1 > *it2 && span < *it1 - *it2) || (*it2 > *it1 && span < *it2 - *it1))
		{
			if (*it1 > *it2)
				span = *it1 - *it2;
			else
				span = *it2 - *it1;
		}
	}
	return span;
	return span;
}

void Span::printList()
{
	for (std::list<unsigned int>::iterator it = this->_list.begin(); it != this->_list.end(); it++)
		std::cout << *it << " ";
}

void Span::addMultipleNumbers(int n)
{
	if ((int)this->getCurr() + n > (int)this->getMax())
		throw e_oof;
	for (int i = 0; i < n; i++)
	{
		this->setCurr(this->getCurr() + 1);
		this->_list.push_back(rand() % 10000 + 1);
	}
}

