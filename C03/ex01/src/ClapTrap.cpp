/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:45:30 by vduchi            #+#    #+#             */
/*   Updated: 2023/09/10 18:45:22 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _HP(10), _EP(10), _AD(0), _name("NoName") { std::cout << "ClapTrap NoName created!" << std::endl; }
ClapTrap::ClapTrap(std::string name) : _HP(10), _EP(10), _AD(0), _name(name) { std::cout << "ClapTrap " << name << " created!" << std::endl; }
ClapTrap::ClapTrap(std::string name, int HP, int EP, int AD) : _HP(HP), _EP(EP), _AD(AD), _name(name) { std::cout << "ClapTrap " << name << " with params created!" << std::endl; }
ClapTrap::~ClapTrap(void) { std::cout << "ClapTrap " << this->_name << " destroyed!" << std::endl; }
ClapTrap::ClapTrap(const ClapTrap &cpy)
{
	this->setHealth(cpy.getHealth());
	this->setDamage(cpy.getDamage());
	this->setEnergy(cpy.getEnergy());
	std::cout << "ClapTrap copy constructor called!" << std::endl;
}

int ClapTrap::getHealth(void) const { return this->_HP; }
int ClapTrap::getEnergy(void) const { return this->_EP; }
int ClapTrap::getDamage(void) const { return this->_AD; }

std::string ClapTrap::getName(void) const { return this->_name; }

void ClapTrap::setName(std::string name) { this->_name = name; }
void ClapTrap::setHealth(int newValue) { this->_HP = newValue; }
void ClapTrap::setEnergy(int newValue) { this->_EP = newValue; }
void ClapTrap::setDamage(int newValue) { this->_AD = newValue; }

void ClapTrap::attack(const std::string &target)
{
	this->setEnergy(this->getEnergy() - 1);
	std::cout << "ClapTrap " << this->getName() << " attack " << target << ", causing " << this->getDamage()
						<< " points of damage! He now has " << this->getEnergy() << " EP" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->setHealth(this->getHealth() - amount);
	std::cout << "ClapTrap " << this->getName() << " now has " << this->getHealth() << " HP and " << this->getEnergy() << " EP" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	this->setEnergy(this->getEnergy() - 1);
	this->setHealth(this->getHealth() + amount);
	std::cout << "ClapTrap " << this->getName() << " is repairing of " << amount
						<< " HP, now he has " << this->getHealth() << " HP and " << this->getEnergy() << " EP" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &cpy)
{
	this->setHealth(cpy.getHealth());
	this->setDamage(cpy.getDamage());
	this->setEnergy(cpy.getEnergy());
	std::cout << "ClapTrap assignment operator called!" << std::endl;
	return *this;
}
