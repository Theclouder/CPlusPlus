/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:01:31 by vduchi            #+#    #+#             */
/*   Updated: 2024/01/25 15:37:13 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include "Colors.hpp"

void addValue(int & v) { v = v + 1; }
void changeName(std::string & name)
{
	if (isupper(name[0]))
		name[0] += 32;
	else
		name[0] -= 32;
}

int main()
{
	{
		std::cout << MAGENTA << "First test" << RESET << std::endl;
		int len = 3;
		int arr[3] = {1, 4, 7};
	
		std::cout << CYAN << "Array values: " << RESET << std::endl;
		for (int i = 0; i < len; i++)
			std::cout << CYAN << "\t" << i << ". -> " << arr[i] << RESET << std::endl;
		iter(arr, len, &addValue);
		std::cout << GREEN << "New array values: " << RESET << std::endl;
		for (int i = 0; i < len; i++)
			std::cout << GREEN << "\t" << i << ". -> " << arr[i] << RESET << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << MAGENTA << "Second test" << RESET << std::endl;
		int len = 3;
		std::string arr[3] = {"Nacho", "valerio", "Meri"};
	
		std::cout << CYAN << "Array values: " << RESET << std::endl;
		for (int i = 0; i < len; i++)
			std::cout << CYAN << "\t" << i << ". -> " << arr[i] << RESET << std::endl;
		iter(arr, len, &changeName);
		std::cout << GREEN << "New array values: " << RESET << std::endl;
		for (int i = 0; i < len; i++)
			std::cout << GREEN << "\t" << i << ". -> " << arr[i] << RESET << std::endl;
	}
}
