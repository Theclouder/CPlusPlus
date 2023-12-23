/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 22:29:37 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/23 21:19:04 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice () : AMateria("ice") {}

Ice::Ice (Ice const & other)
{
	*this = other;
}

Ice& Ice::operator=(Ice const & other)
{
	this->_type = other.getType();
	return *this;
}

Ice::~Ice () {}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& c)
{
	std::cout << "* shoots an ice bolt at " << c.getName() << " *" << std::endl;
}
