/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:15:51 by vduchi            #+#    #+#             */
/*   Updated: 2024/01/29 15:19:35 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int checkInput(char *argv[])
{

	return 0;
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << ORANGE << "The program accept only one argument, ";
		std::cout << ORANGE << "the operation that has to be performed";
		std::cout << RESET << std::endl;
		return 1;
	}
	else if (checkInput(argv))
		return 1;
	try {
		PmergeMe pmm;
	}
	catch (std::exception & ex) { std::cout << RED << ex.what() << RESET << std::endl; }
}
