/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:49:58 by vduchi            #+#    #+#             */
/*   Updated: 2024/01/23 11:09:39 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "Bureaucrat.hpp"

int main()
{
	{
		try
		{
			Bureaucrat test("Valerio", 1);
			std::cout << CYAN <<  test << RESET << std::endl;
			test.gradeUp();
			test.gradeDown();
		}
		catch (std::exception & ex)
		{
			std::cout << RED << ex.what() << RESET << std::endl;
		}
	}
	std::cout << std::endl;
	{
		try
		{
			Bureaucrat test("Nacho", 15);
			std::cout << CYAN <<  test << RESET << std::endl;
			test.gradeUp();
			test.gradeDown();
		}
		catch (std::exception & ex)
		{
			std::cout << RED << ex.what() << RESET << std::endl;
		}
	}
	std::cout << std::endl;
	{
		try
		{
			Bureaucrat test("Giuliano", 150);
			std::cout << CYAN <<  test << RESET << std::endl;
			test.gradeDown();
		}
		catch (std::exception & ex)
		{
			std::cout << RED << ex.what() << RESET << std::endl;
		}
	}
	std::cout << std::endl;
	{
		try
		{
			Bureaucrat test("Hola", 200);
			std::cout << CYAN <<  test << RESET << std::endl;
			test.gradeDown();
		}
		catch (std::exception & ex)
		{
			std::cout << RED << ex.what() << RESET << std::endl;
		}
	}
}
