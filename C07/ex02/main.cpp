/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:01:31 by vduchi            #+#    #+#             */
/*   Updated: 2024/01/25 18:35:54 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Array.tpp"

int main()
{
	{
		std::cout << GREEN << "First test" << RESET << std::endl;
		try
		{
			Array<int> array;
			array[2] = 2;
		}
		catch (std::exception & ex) { std::cout << ex.what() << std::endl; }
	}
	std::cout << std::endl;
	{
		std::cout << GREEN << "Second test" << RESET << std::endl;
		try
		{
			Array<int> array(5);
			array[2] = 2;
			std::cout << CYAN << "Array size: " << array.size() << RESET << std::endl;
		}
		catch (std::exception & ex) { std::cout << ex.what() << std::endl; }
	}
	std::cout << std::endl;
	{
		std::cout << GREEN << "Third test" << RESET << std::endl;
		try
		{
			Array<int> array(5);
			Array<int> second = array;
			std::cout << CYAN << "Before -> " << array[2] << RESET << std::endl;
			array[2] = 2;
			std::cout << CYAN << "After -> " << array[2] << RESET << std::endl;
			std::cout << CYAN << "Before -> " << second[3] << RESET << std::endl;
			second[3] = 2;
			std::cout << CYAN << "After -> " << second[3] << RESET << std::endl;
			std::cout << CYAN << "Array size: " << array.size() << RESET << std::endl;
			second[5] = 6;
		}
		catch (std::exception & ex) { std::cout << ex.what() << std::endl; }
	}
	std::cout << std::endl;
	{
		std::cout << GREEN << "Fourth test" << RESET << std::endl;
		try
		{
			Array<std::string> arr(5);
			Array<std::string> second = arr;
			std::cout << CYAN << "Before -> " << arr[2] << RESET << std::endl;
			arr[2] = "Hola";
			std::cout << CYAN << "After -> " << arr[2] << RESET << std::endl;
			std::cout << CYAN << "Before -> " << second[3] << RESET << std::endl;
			second[3] = "Que tal";
			std::cout << CYAN << "After -> " << second[3] << RESET << std::endl;
			std::cout << CYAN << "Array size: " << arr.size() << RESET << std::endl;
			second[5] = "Ciao";
		}
		catch (std::exception & ex) { std::cout << ex.what() << std::endl; }
	}
}
