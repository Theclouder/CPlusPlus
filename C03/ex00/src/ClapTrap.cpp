/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:45:30 by vduchi            #+#    #+#             */
/*   Updated: 2023/09/08 17:12:17 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _HP(10), _EP(10), _AD(0), _name("NoName") {}
ClapTrap::ClapTrap(std::string name) : _HP(10), _EP(10), _AD(0), _name(name) {}
ClapTrap::~ClapTrap(void) {}

void ClapTrap::attack(const std::string &target)
{
	this->_EP--;
	std::cout << "ClapTrap " << this->_name << " attack " << target << ", causing " << this->_AD << " points of damage! He now has " << this->_EP << " EP" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->_HP -= amount;
	std::cout << "ClapTrap " << this->_name << " is taking " << amount << " damage! Now he has " << this->_HP << " HP and " << this->_EP << " EP" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	this->_EP--;
	this->_HP += amount;
	std::cout << "ClapTrap " << this->_name << " is repairing of " << amount << " HP and he has " << this->_EP << " EP" << std::endl;
}
