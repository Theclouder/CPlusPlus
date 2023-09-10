/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:42:14 by vduchi            #+#    #+#             */
/*   Updated: 2023/09/10 18:26:33 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H__
#define CLAPTRAP_H__

#include <iostream>

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
	std::string getName(void) const;

	void setName(std::string name);
	void setHealth(int newValue);
	void setEnergy(int newValue);
	void setDamage(int newValue);

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

private:
	int _HP;
	int _EP;
	int _AD;
	std::string _name;
};

#endif
