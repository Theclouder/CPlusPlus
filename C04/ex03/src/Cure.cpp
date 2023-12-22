/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 22:32:33 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/22 21:42:53 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure ()
{
	std::cout << "Cure default constructor called!" << std::endl;
}

Cure::Cure (std::string const & type) : AMateria(type)
{
	std::cout << "Cure parameter constructor called!" << std::endl;
}

Cure::Cure (Cure const & other)
{
	*this = other;
	std::cout << "Cure copy constructor called!" << std::endl;
}

Cure& Cure::operator=(Cure const & other)
{
	this->_type = other.getType();
	std::cout << "Cure assignment operator called!" << std::endl;
	return *this;
}

Cure::~Cure ()
{
	std::cout << "Cure destructor called!" << std::endl;
}

AMateria* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& c)
{
	std::cout << "* heals " << c->getName() << "'s wounds *" << std::endl;
}
