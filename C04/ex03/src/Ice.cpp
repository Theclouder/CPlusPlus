/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 22:29:37 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/22 21:43:01 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice ()
{
	std::cout << "Ice default constructor called!" << std::endl;
}

Ice::Ice (std::string const & type) : AMateria(type)
{
	std::cout << "Ice parameter constructor called!" << std::endl;
}

Ice::Ice (Ice const & other)
{
	*this = other;
	std::cout << "Ice copy constructor called!" << std::endl;
}

Ice& Ice::operator=(Ice const & other)
{
	this->_type = other.getType();
	std::cout << "Ice assignment operator called!" << std::endl;
	return *this;
}

Ice::~Ice ()
{
	std::cout << "Ice destructor called!" << std::endl;
}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& c)
{
	std::cout << "* shoots an ice bolt at " << c->getName() << " *" << std::endl;
}
