/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 21:37:30 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/23 21:18:22 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria () : _type("None") {}

AMateria::AMateria (std::string const & type) : _type(type) {}

AMateria::AMateria (AMateria const & other)
{
	*this = other;
}

AMateria& AMateria::operator=(AMateria const & other)
{
	this->_type = other.getType();
	return *this;
}

AMateria::~AMateria () {}

std::string const & AMateria::getType() const
{
	return this->_type;
}

void AMateria::use(ICharacter & c)
{
	std::cout << "* shoots an ice bolt at " << c.getName() << " *" << std::endl;
}

