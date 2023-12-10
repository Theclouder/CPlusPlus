/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:45:30 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/10 13:25:45 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("NoName"), FragTrap("NoName"), ScavTrap("NoName")
{
	this->_name = "NoName";
	this->setHealth(this->FragTrap::getHealth());
	this->setEnergy(this->ScavTrap::getEnergy());
	this->setDamage(this->FragTrap::getDamage());
	std::cout << "DiamondTrap created!" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << this->getName() << " destroyed!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	this->_name = name;
	this->setHealth(this->FragTrap::getHealth());
	this->setEnergy(this->ScavTrap::getEnergy());
	this->setDamage(this->FragTrap::getDamage());
	std::cout << "DiamondTrap " << name << " created!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &cpy) : ClapTrap(cpy.getName() + "_clap_name"), FragTrap(cpy.getName()), ScavTrap(cpy.getName())
{
	*this = cpy;
	std::cout << "DiamondTrap copy assignment called!" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &cpy)
{
	this->setName(cpy.getName());
	this->setClapTrapName(cpy.getClapTrapName());
	this->setHealth(cpy.getHealth());
	this->setDamage(cpy.getDamage());
	this->setEnergy(cpy.getEnergy());
	std::cout << "DiamondTrap " << cpy.getName() << " assignment operator called!" << std::endl;
	return *this;
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "Diamond name: " << this->getName() << " and ClapTrap name: " << this->getClapTrapName() << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::setName(std::string name)
{
	this->_name = name;
	this->setClapTrapName(name);
}

std::string DiamondTrap::getName(void) const { return this->_name; }
std::string DiamondTrap::getClapTrapName(void) const { return this->ClapTrap::_name; }
void DiamondTrap::setClapTrapName(std::string name) { this->ClapTrap::_name = name + "_clap_name"; }

std::ostream &operator<<(std::ostream &out, DiamondTrap &diamond)
{
	out << "Name: " << diamond.getName() << " ClapTrap Name: "
			<< diamond.getClapTrapName() << " Hit points: "
			<< diamond.getHealth() << " Energy Points: " << diamond.getEnergy()
			<< " Attack Damage: " << diamond.getDamage();
	return (out);
}
