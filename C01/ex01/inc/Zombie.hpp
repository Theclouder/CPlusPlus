/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 16:17:06 by vduchi            #+#    #+#             */
/*   Updated: 2023/09/03 19:08:05 by vduchi           ###   ########.fr       */
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

Zombie *zombieHorde(int N, std::string name);

#endif
