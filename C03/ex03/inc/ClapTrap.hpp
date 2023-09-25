/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:42:14 by vduchi            #+#    #+#             */
/*   Updated: 2023/09/25 10:10:03 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H__
#define CLAPTRAP_H__

#include <iostream>

#define CLAP_HEALTH_DEF 10
#define CLAP_ENERGY_DEF 10
#define CLAP_DAMAGE_DEF 0

class ClapTrap
{
public:
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(std::string name, int HP, int EP, int AD);
	ClapTrap(const ClapTrap &cpy);
	~ClapTrap(void);
	ClapTrap &operator=(const ClapTrap &cpy);

	int getHealth(void) const;
	int getEnergy(void) const;
	int getDamage(void) const;
	virtual std::string getName(void) const;

	virtual void setName(std::string name);
	void setHealth(int newValue);
	void setEnergy(int newValue);
	void setDamage(int newValue);

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

protected:
	int _HP;
	int _EP;
	int _AD;
	std::string _name;
};

void print_message(ClapTrap &inst, int idx, const std::string &target, int amount);

std::ostream &operator<<(std::ostream &out, ClapTrap &clap);

#endif
