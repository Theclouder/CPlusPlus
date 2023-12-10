/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:42:14 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/10 13:16:28 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

#define CLAP_HEALTH_DEF 10
#define CLAP_ENERGY_DEF 10
#define CLAP_DAMAGE_DEF 0

class ClapTrap
{

public:
	ClapTrap(void);
	ClapTrap(std::string);
	ClapTrap(std::string, int, int, int);
	ClapTrap(const ClapTrap &);
	~ClapTrap(void);
	ClapTrap &operator=(const ClapTrap &);

	int getHealth(void) const;
	int getEnergy(void) const;
	int getDamage(void) const;
	std::string getName(void) const;

	void setName(std::string);
	void setHealth(int);
	void setEnergy(int);
	void setDamage(int);

	void attack(const std::string &);
	void takeDamage(unsigned int);
	void beRepaired(unsigned int);

private:
	int _HP;
	int _EP;
	int _AD;
	std::string _name;
};

void print_message(ClapTrap &, int, const std::string &, int);

#endif
