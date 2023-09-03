/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 18:36:55 by vduchi            #+#    #+#             */
/*   Updated: 2023/09/03 19:22:42 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H__
#define WEAPON_H__

#include <iostream>

class Weapon
{
public:
	Weapon(std::string type);
	~Weapon(void);

	const std::string &getType();
	void setType(std::string newType);

private:
	std::string _type;
};

#endif
