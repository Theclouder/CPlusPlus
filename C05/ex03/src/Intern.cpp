/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:39:47 by vduchi            #+#    #+#             */
/*   Updated: 2024/01/28 12:27:45 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern & rhs)
{
	*this = rhs;
}

Intern& Intern::operator=(const Intern & rhs) { (void)rhs; return *this; }

Intern::~Intern() {}

AForm *Intern::makeForm(const std::string name, const std::string target) const
{
	int i;
	std::string arr[3];
	arr[0] = "robotomy request";
	arr[1] = "shrubbery creation";
	arr[2] = "presidential pardon";
	for (i = 0; i < 3; i++)
		if (arr[i].compare(name) == 0)
			break;
	switch (i) {
		case 0:
			{	std::cout << GREEN << "Intern creates " << name << RESET << "!" << std::endl;
				return new RobotomyRequestForm(target); }
		case 1:
			{	std::cout << GREEN << "Intern creates " << name << RESET << "!" << std::endl;
				return new ShrubberyCreationForm(target); }
		case 2:
			{	std::cout << GREEN << "Intern creates " << name << RESET << "!" << std::endl;
				return new PresidentialPardonForm(target); }
		default:
			{
				std::cout << RED << "The form " << name << " cannot be created!" << RESET << std::endl;
				return nullptr;
			}
	}
}

