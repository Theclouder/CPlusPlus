/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 09:54:24 by vduchi            #+#    #+#             */
/*   Updated: 2023/09/03 18:27:39 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie first;
	Zombie second;

	first.setName("Paolo");
	second.setName("Luca");

	first.announce();
	second.announce();

	// Now with the functions implemented
	Zombie *third = zombieHorde(8, "Giorgio");
	for (int i = 0; i < 8; i++)
		third[i].announce();

	delete[] third;
}
