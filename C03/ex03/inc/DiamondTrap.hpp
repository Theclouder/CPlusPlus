/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:42:14 by vduchi            #+#    #+#             */
/*   Updated: 2023/09/25 10:08:25 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H__
#define DIAMONDTRAP_H__

#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
public:
	DiamondTrap(void);
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &cpy);
	DiamondTrap &operator=(const DiamondTrap &cpy);
	~DiamondTrap(void);

	void whoAmI(void);
	void attack(const std::string &target);
	void setName(std::string name);
	std::string getName(void) const;
	void setClapTrapName(std::string name);
	std::string getClapTrapName(void) const;

private:
	std::string _name;
};

std::ostream &operator<<(std::ostream &out, DiamondTrap &diamond);

#endif
