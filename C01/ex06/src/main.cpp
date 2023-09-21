/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:37:59 by vduchi            #+#    #+#             */
/*   Updated: 2023/09/21 20:22:16 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char *argv[])
{
	Harl harl;

	if (argc != 2 || (std::string(argv[1]).compare("DEBUG") != 0 && std::string(argv[1]).compare("INFO") != 0 && std::string(argv[1]).compare("WARNING") != 0 && std::string(argv[1]).compare("ERROR") != 0))
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return (0);
	}
	harl.complain(argv[1]);
}
