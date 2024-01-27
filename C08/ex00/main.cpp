/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:07:52 by vduchi            #+#    #+#             */
/*   Updated: 2024/01/26 18:39:33 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "easyfind.hpp"

int main()
{
	{
		try {
			std::list<int> v;
			std::list<int>::iterator it;
			for (int i = 0; i < 5; i++)
				v.push_back(i);
			std::cout << CYAN << "List values: ";
			for (it = v.begin(); it != v.end(); it++)
				std::cout << *it << " ";
			std::cout << RESET << std::endl;
			int to_find = 2;
			std::cout << YELLOW << "Easyfind with " << to_find << RESET << std::endl;
			std::cout << GREEN << easyfind(v, to_find) << RESET << std::endl;
			to_find = 4;
			std::cout << YELLOW << "Easyfind with " << to_find << RESET << std::endl;
			std::cout << GREEN << easyfind(v, to_find) << RESET << std::endl;
			to_find = 6;
			std::cout << YELLOW << "Easyfind with " << to_find << RESET << std::endl;
			std::cout << GREEN << easyfind(v, to_find) << RESET << std::endl;
		}
		catch (NotFoundException & ex) { std::cout << RED << ex.what() << RESET << std::endl; }
	}
	std::cout << std::endl;
	{
		try {
			std::array<int, 5> v = {1, 3, 4, 9, 87};
			std::array<int, 5>::iterator it;
			std::cout << CYAN << "Array values: ";
			for (it = v.begin(); it != v.end(); it++)
				std::cout << *it << " ";
			std::cout << RESET << std::endl;
			int to_find = 4;
			std::cout << YELLOW << "Easyfind with " << to_find << RESET << std::endl;
			std::cout << GREEN << easyfind(v, to_find) << RESET << std::endl;
			to_find = 88;
			std::cout << YELLOW << "Easyfind with " << to_find << RESET << std::endl;
			std::cout << GREEN << easyfind(v, to_find) << RESET << std::endl;
		}
		catch (NotFoundException & ex) { std::cout << RED << ex.what() << RESET << std::endl; }
	}
	std::cout << std::endl;
	{
		try {
			std::vector<int> v;
			std::vector<int>::iterator it;
			for (int i = 0; i < 5; i++)
				v.push_back(i);
			std::cout << CYAN << "Vector values: ";
			for (it = v.begin(); it != v.end(); it++)
				std::cout << *it << " ";
			std::cout << RESET << std::endl;
			int to_find = 4;
			std::cout << YELLOW << "Easyfind with " << to_find << RESET << std::endl;
			std::cout << GREEN << easyfind(v, to_find) << RESET << std::endl;
			to_find = 6;
			std::cout << YELLOW << "Easyfind with " << to_find << RESET << std::endl;
			std::cout << GREEN << easyfind(v, to_find) << RESET << std::endl;
		}
		catch (NotFoundException & ex) { std::cout << RED << ex.what() << RESET << std::endl; }
	}
}
