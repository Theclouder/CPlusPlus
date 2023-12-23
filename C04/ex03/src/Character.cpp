/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 22:52:57 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/23 21:21:02 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character ()
{
	for (int i = 0; i < 4; i++)
		this->_slots[i] = NULL;
}

Character::Character (std::string const & name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_slots[i] = NULL;
}

Character::Character (Character const & other)
{
	*this = other;
}

Character& Character::operator=(Character const & other)
{
	this->_name = other.getName();
	for (int i = 0; i < 4; i++)
	{
		if (this->_slots[i] != NULL)
		{
			delete this->_slots[i];
			this->_slots[i] = NULL;
		}
		if (other._slots[i] != NULL)
			this->_slots[i] = other._slots[i];
	}
	return *this;
}

Character::~Character ()
{
	for (int i = 0; i < 4; i++)
		if (this->_slots[i] != NULL)
			delete this->_slots[i];
}

void Character::unequip(int i)
{
	if (i < 0 || i > 3)
		std::cout << "Unequip index out of range" << std::endl;
	else if (this->_slots[i] == NULL)
		std::cout << "Materia already unequipped or not equipped" << std::endl;
	else
	{
		this->_bag.addNode(this->_slots[i]);
		this->_slots[i] = NULL;
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
	else if (this->_slots[i] == NULL)
	{
		std::cout << "Don't have this weapon equipped!" << std::endl;
		return ;
	}
	this->_slots[i]->use(c);
}

std::string const & Character::getName() const
{
	return this->_name;
}
