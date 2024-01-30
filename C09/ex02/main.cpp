/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:15:51 by vduchi            #+#    #+#             */
/*   Updated: 2024/01/30 10:08:16 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int checkInput(char *argv[])
{
	try {
		std::vector<int> v;
		for (int i = 1; argv[i] != NULL; i++)
			for (int l = 0; argv[i][l] != '\0'; l++)
				if (!isdigit(argv[i][l]))
					throw std::invalid_argument("one of the arguments is not a positive int!");
		for (int i = 1; argv[i] != NULL; i++)
			v.push_back(atoi(argv[i]));
		for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		{
			std::vector<int>::iterator it2 = it;
			it2++;
			for (; it2 != v.end(); it2++)
				if (*it2 == *it) {
//					std::cout << RED << *it << " " << *it2 << std::endl;
//					throw std::invalid_argument("one of the integers is repeated!");
				}
		}
	}
	catch (std::exception & ex) { std::cout << RED << "Error => " << ex.what() << RESET << std::endl; return 1; }
	return 0;
}

int main(int argc, char *argv[])
{
	std::vector<int> v;
	if (argc == 1)
	{
		std::cout << ORANGE << "The program needs at least one argument!";
		std::cout << RESET << std::endl;
		return 1;
	}
	else if (checkInput(argv))
		return 1;
	try {
		PmergeMe pmm;
		pmm.startListAlgorithm(argv);
		pmm.startVectorAlgorithm(argv);
		pmm.printET(argv);
	}
	catch (std::exception & ex) { std::cout << RED << ex.what() << RESET << std::endl; }
}
