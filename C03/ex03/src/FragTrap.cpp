/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:45:30 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/10 13:24:55 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("NoName", FRAG_HEALTH_DEF, FRAG_ENERGY_DEF, FRAG_DAMAGE_DEF)
{
	std::cout << "FragTrap created!" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << this->getName() << " destroyed!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, FRAG_HEALTH_DEF, FRAG_ENERGY_DEF, FRAG_DAMAGE_DEF)
{
	std::cout << "FragTrap " << this->getName() << " created!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &cpy) : ClapTrap(cpy)
{
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

std::ostream &operator<<(std::ostream &out, FragTrap &frag)
{
	out << "Name: " << frag.getName() << " Hit points: " << frag.getHealth()
			<< " Energy Points: " << frag.getEnergy() << " Attack Damage: " << frag.getDamage();
	return (out);
}
