/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:45:30 by vduchi            #+#    #+#             */
/*   Updated: 2023/09/10 18:36:34 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("NoName", 100, 50, 20) { std::cout << "ScavTrap created!" << std::endl; }
ScavTrap::~ScavTrap(void) { std::cout << "ScavTrap " << this->getName() << " destroyed!" << std::endl; }
ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20) { std::cout << "ScavTrap " << name << " created!" << std::endl; }
ScavTrap::ScavTrap(const ScavTrap &cpy) : ClapTrap(cpy.getName())
{
	this->setName(cpy.getName());
	this->setHealth(cpy.getHealth());
	this->setEnergy(cpy.getEnergy());
	this->setDamage(cpy.getDamage());
	std::cout << "ScavTrap copy assignment called!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &cpy)
{
	this->setHealth(cpy.getHealth());
	this->setDamage(cpy.getDamage());
	this->setEnergy(cpy.getEnergy());
	std::cout << "ScavTrap assignment operator called!" << std::endl;
	return *this;
}

void ScavTrap::attack(const std::string &target)
{
	this->setEnergy(this->getEnergy() - 1);
	std::cout << "ScavTrap " << this->getName() << " attack " << target << ", causing " << this->getDamage()
						<< " points of damage! He now has " << this->getEnergy() << " EP" << std::endl;
}

void ScavTrap::guardGate(void) { std::cout << "ScavTrap " << this->getName() << " guarding the Gate!" << std::endl; }
