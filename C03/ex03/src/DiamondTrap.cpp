/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:45:30 by vduchi            #+#    #+#             */
/*   Updated: 2023/09/10 18:43:19 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), FragTrap(), ScavTrap() { std::cout << "DiamondTrap created!" << std::endl; }
DiamondTrap::~DiamondTrap(void) { std::cout << "DiamondTrap " << this->getName() << " destroyed!" << std::endl; }
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	this->setName(name);
	this->setHealth(this->FragTrap::getHealth());
	this->setEnergy(this->ScavTrap::getEnergy());
	this->setDamage(this->FragTrap::getDamage());
	std::cout << "DiamondTrap " << name << " created!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &cpy) : ClapTrap(cpy.getName() + "_clap_name"), FragTrap(cpy.getName()), ScavTrap(cpy.getName())
{
	this->setName(cpy.getName());
	this->setHealth(this->FragTrap::getHealth());
	this->setEnergy(this->ScavTrap::getEnergy());
	this->setDamage(this->FragTrap::getDamage());
	std::cout << "DiamondTrap copy assignment called!" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &cpy)
{
	this->setName(cpy.getName());
	this->setHealth(cpy.getHealth());
	this->setDamage(cpy.getDamage());
	this->setEnergy(cpy.getEnergy());
	std::cout << "DiamondTrap assignment operator called!" << std::endl;
	return *this;
}

void DiamondTrap::whoAmI(void) { std::cout << "Diamond name: " << this->getName() << " and ClapTrap name: " << this->ClapTrap::getName() << std::endl; }

void DiamondTrap::attack(const std::string &target) { ScavTrap::attack(target); }
