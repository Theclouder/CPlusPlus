/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:42:14 by vduchi            #+#    #+#             */
/*   Updated: 2023/09/25 10:09:03 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H__
#define FRAGTRAP_H__

#include <iostream>
#include "ClapTrap.hpp"

#define FRAG_HEALTH_DEF 100
#define FRAG_ENERGY_DEF 100
#define FRAG_DAMAGE_DEF 30

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(const FragTrap &cpy);
	FragTrap &operator=(const FragTrap &cpy);
	~FragTrap(void);

	void highFiveGuys(void);
	void attack(const std::string &target);
};

std::ostream &operator<<(std::ostream &out, FragTrap &frag);

#endif
