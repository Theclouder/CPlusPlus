/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 22:32:33 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/23 21:18:47 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure () : AMateria("cure") {}

Cure::Cure (Cure const & other)
{
	*this = other;
}

Cure& Cure::operator=(Cure const & other)
{
	this->_type = other.getType();
	return *this;
}

Cure::~Cure () {}

AMateria* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& c)
{
	std::cout << "* heals " << c.getName() << "'s wounds *" << std::endl;
}
