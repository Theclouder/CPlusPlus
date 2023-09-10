/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:45:30 by vduchi            #+#    #+#             */
/*   Updated: 2023/09/10 18:39:48 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("NoName", 100, 100, 30) { std::cout << "FragTrap created!" << std::endl; }
FragTrap::~FragTrap(void) { std::cout << "FragTrap " << this->getName() << " destroyed!" << std::endl; }
FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30) { std::cout << "FragTrap " << name << " created!" << std::endl; }
FragTrap::FragTrap(const FragTrap &cpy) : ClapTrap(cpy.getName())
{
	this->setName(cpy.getName());
	this->setHealth(cpy.getHealth());
	this->setEnergy(cpy.getEnergy());
	this->setDamage(cpy.getDamage());
	std::cout << "FragTrap copy assignment called!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &cpy)
{
	this->setName(cpy.getName());
	this->setHealth(cpy.getHealth());
	this->setDamage(cpy.getDamage());
	this->setEnergy(cpy.getEnergy());
	std::cout << "FragTrap assignment operator called!" << std::endl;
	return *this;
}

void FragTrap::attack(const std::string &target)
{
	this->setEnergy(this->getEnergy() - 1);
	std::cout << "FragTrap " << this->getName() << " attack " << target << ", causing " << this->getDamage()
						<< " points of damage! He now has " << this->getEnergy() << " EP" << std::endl;
}

void FragTrap::highFiveGuys(void) { std::cout << "High five to the FragTrap!" << std::endl; }
