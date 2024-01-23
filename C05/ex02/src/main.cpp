/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:49:58 by vduchi            #+#    #+#             */
/*   Updated: 2024/01/23 17:28:59 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Colors.hpp"
#include "../inc/Bureaucrat.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

int main()
{
	{
		try
		{
			Bureaucrat test("Valerio", 20);
			std::cout << CYAN << test << RESET;
			PresidentialPardonForm ppf("home");
			test.executeForm(ppf);
		}
		catch (std::exception & ex) { std::cout << RED << ex.what() << RESET << std::endl; }
	}
	std::cout << std::endl;
	{
		try
		{
			Bureaucrat test("Valerio", 20);
			std::cout << CYAN << test << RESET;
			PresidentialPardonForm ppf("home");
			test.signForm(ppf);
			test.executeForm(ppf);
		}
		catch (std::exception & ex) { std::cout << RED << ex.what() << RESET << std::endl; }
	}
	std::cout << std::endl;
	{
		try
		{
			Bureaucrat test("Valerio", 2);
			std::cout << CYAN << test << RESET;
			PresidentialPardonForm ppf("home");
			test.signForm(ppf);
			test.executeForm(ppf);
		}
		catch (std::exception & ex) { std::cout << RED << ex.what() << RESET << std::endl; }
	}
	std::cout << std::endl;
	{
		try
		{
			Bureaucrat test("Valerio", 2);
			std::cout << CYAN << test << RESET;
			RobotomyRequestForm rrf1("Me");
			RobotomyRequestForm rrf2("Nacho");
			RobotomyRequestForm rrf3("Meri");
			ShrubberyCreationForm scf("You");
			PresidentialPardonForm ppf("Home");
			std::cout << std::endl;
			test.signForm(rrf1);
			test.signForm(rrf2);
			test.signForm(rrf3);
			test.signForm(scf);
			test.signForm(ppf);
			std::cout << std::endl;
			test.executeForm(scf);
			test.executeForm(ppf);
			test.executeForm(rrf1);
			test.executeForm(rrf2);
			test.executeForm(rrf3);
		}
		catch (std::exception & ex) { std::cout << RED << ex.what() << RESET << std::endl; }
	}
}
