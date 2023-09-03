/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 16:17:06 by vduchi            #+#    #+#             */
/*   Updated: 2023/09/03 19:08:07 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H__
#define ZOMBIE_H__
#include <iostream>

class Zombie
{
public:
	Zombie(void);
	~Zombie();

	void announce(void);
	void setName(std::string name);

private:
	std::string _name;
};

void randomChump(std::string name);
Zombie *newZombie(std::string name);

#endif
