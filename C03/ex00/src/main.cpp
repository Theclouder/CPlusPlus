/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:55:31 by vduchi            #+#    #+#             */
/*   Updated: 2023/09/08 17:06:05 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap one("one");
	ClapTrap two("two");
	ClapTrap three("three");

	one.attack("two");
	two.attack("three");
	three.attack("one");

	one.takeDamage(2);
	two.takeDamage(3);
	three.takeDamage(5);

	one.beRepaired(1);
	two.beRepaired(2);
	three.beRepaired(2);
}
