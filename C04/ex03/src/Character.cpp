/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 22:52:57 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/19 15:16:49 by vduchi           ###   ########.fr       */
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

void Character::unequip(int i)
{
	if (i < 0 || i > 3)
		std::cout << "Unequip index out of range" << std::endl;
	else if (this->_slots[i] == NULL)
		std::cout << "Materia already unequipped or not equipped" << std::endl;
	else
	{
	}
}

void Character::equip(AMateria* mat)
{
	if (this->_slots[3] != NULL)
		std::cout << "Already have 4 Materias, cannot add one more!" << std::endl;
	else
	{
		int i = 0;
		while (this->_slots[i] != NULL)
			i++;
		this->_slots[i] = mat;
	}
}

void Character::use(int i, ICharacter& c)
{
	if (i < 0 || i > 3)
	{
		std::cout << "Use index out of range" << std::endl;
		return ;
	}
	*(this->_slots[i])::use(c);
}

std::string const & Character::getName()
{
	return this->_name;
}
