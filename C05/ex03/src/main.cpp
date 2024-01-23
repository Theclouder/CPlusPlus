/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:49:58 by vduchi            #+#    #+#             */
/*   Updated: 2024/01/23 18:06:17 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"
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
			Intern someRandomIntern;
			AForm *rrf;
			AForm *scf;
			AForm *ppf;
			rrf = someRandomIntern.makeForm("robotomy reques", "Bender");
			rrf = someRandomIntern.makeForm("robotomy request", "Eva");
			scf = someRandomIntern.makeForm("shrubber creatio", "Eva");
			scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
			ppf = someRandomIntern.makeForm("presidentia pard", "Nacho");
			ppf = someRandomIntern.makeForm("presidential pardon", "Meri");
			std::cout << std::endl;
			test.signForm(*rrf);
			test.signForm(*scf);
			test.signForm(*ppf);
			std::cout << std::endl;
			test.executeForm(*scf);
			test.executeForm(*ppf);
			test.executeForm(*rrf);
			delete rrf;
			delete scf;
			delete ppf;
		}
		catch (std::exception & ex) { std::cout << RED << ex.what() << RESET << std::endl; }
	}
}
