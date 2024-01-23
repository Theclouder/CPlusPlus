/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:49:58 by vduchi            #+#    #+#             */
/*   Updated: 2024/01/23 12:45:18 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Colors.hpp"
#include "Bureaucrat.hpp"

int main()
{
	{
		try
		{
			Bureaucrat test("Valerio", 1);
			std::cout << CYAN << test << RESET << std::endl;
			test.gradeUp();
		}
		catch (std::exception & ex) { std::cout << RED << ex.what() << RESET << std::endl; }
	}
	std::cout << std::endl;
	{
		try
		{
			Bureaucrat test("Nacho", 15);
			std::cout << CYAN << test << RESET << std::endl;
			test.gradeUp();
			test.gradeDown();
		}
		catch (std::exception & ex) { std::cout << RED << ex.what() << RESET << std::endl; }
	}
	std::cout << std::endl;
	{
		try { Form test("test", 160, 15); }
		catch (std::exception & ex) { std::cout << RED << ex.what() << RESET << std::endl; }
	}
	std::cout << std::endl;
	{
		try { Form test("test", 15, -15); }
		catch (std::exception & ex) { std::cout << RED << ex.what() << RESET << std::endl; }
	}
	std::cout << std::endl;
	{
		try
		{
			Form form("form", 15, 16);
			Bureaucrat test("Test", 16);
			std::cout << CYAN << test << RESET << std::endl;
			std::cout << CYAN << form << RESET << std::endl;
			test.signForm(form);
		}
		catch (std::exception & ex) { std::cout << RED << ex.what() << RESET << std::endl; }
	}
	std::cout << std::endl;
	{
		try
		{
			Form form("form", 15, 16);
			Bureaucrat test("Test", 14);
			std::cout << CYAN << test << RESET << std::endl;
			std::cout << CYAN << form << RESET << std::endl;
			test.signForm(form);
			test.signForm(form);
		}
		catch (std::exception & ex) { std::cout << RED << ex.what() << RESET << std::endl; }
	}
	std::cout << std::endl;
}
