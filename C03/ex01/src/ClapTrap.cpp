/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:45:30 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/10 13:19:40 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//	Constructors and Destructors
ClapTrap::ClapTrap(void)
{
	this->setName("NoName");
	this->setHealth(CLAP_HEALTH_DEF);
	this->setEnergy(CLAP_ENERGY_DEF);
	this->setDamage(CLAP_DAMAGE_DEF);
	std::cout << "ClapTrap NoName created!" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->setName(name);
	this->setHealth(CLAP_HEALTH_DEF);
	this->setEnergy(CLAP_ENERGY_DEF);
	this->setDamage(CLAP_DAMAGE_DEF);
	std::cout << "ClapTrap " << name << " created!" << std::endl;
}

ClapTrap::ClapTrap(std::string name, int HP, int EP, int AD) : _HP(HP), _EP(EP), _AD(AD), _name(name)
{
	this->setName(name);
	this->setHealth(HP);
	this->setEnergy(EP);
	this->setDamage(AD);
	std::cout << "ClapTrap " << name << " with params created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &cpy)
{
	*this = cpy;
	std::cout << "ClapTrap copy constructor called!" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->_name << " destroyed!" << std::endl;
}

//	Getters
int ClapTrap::getHealth(void) const { return this->_HP; }
int ClapTrap::getEnergy(void) const { return this->_EP; }
int ClapTrap::getDamage(void) const { return this->_AD; }
std::string ClapTrap::getName(void) const { return this->_name; }

//	Setters
void ClapTrap::setName(std::string name) { this->_name = name; }
void ClapTrap::setHealth(int newValue) { this->_HP = newValue; }
void ClapTrap::setEnergy(int newValue) { this->_EP = newValue; }
void ClapTrap::setDamage(int newValue) { this->_AD = newValue; }

//	Functions
void ClapTrap::attack(const std::string &target)
{
	if (this->getEnergy() <= 0)
		print_message(*this, 3, "None", 0);
	else
	{
		this->setEnergy(this->getEnergy() - 1);
		print_message(*this, 0, target, 0);
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->setHealth(this->getHealth() - amount);
	print_message(*this, 1, "None", amount);
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getEnergy() <= 0)
		print_message(*this, 3, "None", 0);
	else
	{
		this->setEnergy(this->getEnergy() - 1);
		this->setHealth(this->getHealth() + amount);
		print_message(*this, 2, "None", amount);
	}
}

ClapTrap &ClapTrap::operator=(const ClapTrap &cpy)
{
	this->setName(cpy.getName());
	this->setHealth(cpy.getHealth());
	this->setDamage(cpy.getDamage());
	this->setEnergy(cpy.getEnergy());
	std::cout << "ClapTrap assignment operator called!" << std::endl;
	return *this;
}

void print_message(ClapTrap &inst, int idx, const std::string &target, int amount)
{
	switch (idx)
	{
	case 0:
		std::cout << "ClapTrap " << inst.getName() << " attack " << target << ", causing " << inst.getDamage()
							<< " points of damage! He now has " << inst.getEnergy() << " EP" << std::endl;
		break;
	case 1:
		std::cout << "ClapTrap " << inst.getName() << " now has " << inst.getHealth() << " HP and " << inst.getEnergy() << " EP" << std::endl;
		break;
	case 2:
		std::cout << "ClapTrap " << inst.getName() << " is repairing of " << amount
							<< " HP, now he has " << inst.getHealth() << " HP and " << inst.getEnergy() << " EP" << std::endl;
		break;
	case 3:
		std::cout << "ClapTrap " << inst.getName() << " has no energy left!" << std::endl;
	}
}
