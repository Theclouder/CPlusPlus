/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:42:14 by vduchi            #+#    #+#             */
/*   Updated: 2023/09/22 20:47:24 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H__
#define SCAVTRAP_H__

#include <iostream>
#include "ClapTrap.hpp"

#define SCAV_HEALTH_DEF 100
#define SCAV_ENERGY_DEF 50
#define SCAV_DAMAGE_DEF 20

class ScavTrap : public ClapTrap
{
public:
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &cpy);
	ScavTrap &operator=(const ScavTrap &cpy);
	~ScavTrap(void);

	void guardGate(void);
	void attack(const std::string &target);
};

#endif
