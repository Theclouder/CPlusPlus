/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 09:54:24 by vduchi            #+#    #+#             */
/*   Updated: 2023/09/03 16:33:27 by vduchi           ###   ########.fr       */
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
	Zombie *third = newZombie("Giorgio");
	third->announce();
	randomChump("Giovanni");

	delete third;
}
