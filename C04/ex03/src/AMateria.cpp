/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 21:37:30 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/16 22:28:24 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria ()
{
	std::cout << "AMateria default constructor called!" << std::endl;
}

AMateria::AMateria (std::string const & type)
{
	this->_type = type;
	std::cout << "AMateria of type " << type << " created!" << std::endl;
}

AMateria::AMateria (AMateria const & other)
{
	*this = other;
	std::cout << "AMateria copy constructor called!" << std::endl;
}

AMateria& AMateria::operator=(AMateria const & other)
{
	this->_type = other.getType();
	std::cout << "AMateria assignment operator called!" << std::endl;
	return *this;
}

AMateria::~AMateria ()
{
	std::cout << "AMateria destructor called!" << std::endl;
}

std::string const & AMateria::getType() const:
{
	return this->_type;
}
