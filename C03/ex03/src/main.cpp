/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:55:31 by vduchi            #+#    #+#             */
/*   Updated: 2023/10/16 17:56:35 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	ClapTrap one("one");
	ClapTrap two("two");

	DiamondTrap four("four");
	DiamondTrap five(four);
	five.setName("five");

	one.attack("two");
	two.takeDamage(one.getDamage());
	two.attack("one");
	one.takeDamage(two.getDamage());

	four.attack("five");
	five.takeDamage(four.getDamage());
	five.attack("four");
	four.takeDamage(five.getDamage());

	one.takeDamage(2);
	two.takeDamage(3);
	four.takeDamage(2);
	five.takeDamage(3);

	one.beRepaired(1);
	two.beRepaired(2);
	four.beRepaired(1);
	five.beRepaired(2);

	four.whoAmI();
	five.whoAmI();
}
