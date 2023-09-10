/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:55:31 by vduchi            #+#    #+#             */
/*   Updated: 2023/09/10 17:03:58 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap one("one");
	ClapTrap two("two");
	ClapTrap three("three");

	ScavTrap four("four");
	ScavTrap five("five");
	ScavTrap six("six");

	one.attack("two");
	two.takeDamage(one.getDamage());
	two.attack("three");
	three.takeDamage(two.getDamage());
	three.attack("one");
	one.takeDamage(three.getDamage());

	four.attack("five");
	five.takeDamage(four.getDamage());
	five.attack("six");
	six.takeDamage(five.getDamage());
	six.attack("four");
	four.takeDamage(six.getDamage());

	one.takeDamage(2);
	two.takeDamage(3);
	three.takeDamage(5);
	four.takeDamage(2);
	five.takeDamage(3);
	six.takeDamage(5);

	one.beRepaired(1);
	two.beRepaired(2);
	three.beRepaired(2);
	four.beRepaired(1);
	five.beRepaired(2);
	six.beRepaired(2);

	four.guardGate();
	five.guardGate();
	six.guardGate();
}
