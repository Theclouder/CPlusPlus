/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:45:30 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/10 13:24:25 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("NoName", SCAV_HEALTH_DEF, SCAV_ENERGY_DEF, SCAV_DAMAGE_DEF)
{
	std::cout << "ScavTrap created!" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->getName() << " destroyed!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, SCAV_HEALTH_DEF, SCAV_ENERGY_DEF, SCAV_DAMAGE_DEF)
{
	std::cout << "ScavTrap " << this->getName() << " created!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &cpy) : ClapTrap(cpy)
{
	std::cout << "ScavTrap copy assignment called!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &cpy)
{
	this->setName(cpy.getName());
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

std::ostream &operator<<(std::ostream &out, ScavTrap &scav)
{
	out << "Name: " << scav.getName() << " Hit points: " << scav.getHealth()
			<< " Energy Points: " << scav.getEnergy() << " Attack Damage: " << scav.getDamage();
	return (out);
}
