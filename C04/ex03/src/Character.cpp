/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 22:52:57 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/16 22:54:51 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character ()
{
	std::cout << "Character default constructor called!" << std::endl;
}

Character::Character (std::string const & name) : _name(name)
{
	std::cout << "Character of name " << name << " created!" << std::endl;
}

Character::Character (Character const & other)
{
	*this = other;
	std::cout << "Character copy constructor called!" << std::endl;
}

Character& Character::operator=(Character const & other)
{
	this->_name = other.getName();
	std::cout << "Character assignment operator called!" << std::endl;
	return *this;
}

Character::~Character ()
{
	std::cout << "Character destructor called!" << std::endl;
}
