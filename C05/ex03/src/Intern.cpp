/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:39:47 by vduchi            #+#    #+#             */
/*   Updated: 2024/01/23 18:05:35 by vduchi           ###   ########.fr       */
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
	std::map<std::string, int> arr;
	arr["robotomy request"] = 1;
	arr["shrubbery creation"] = 2;
	arr["presidential pardon"] = 3;
	if (arr.find(name) != arr.end())
	{
		std::cout << GREEN << "Intern creates " << name << RESET << "!" << std::endl;
		switch (arr.find(name)->second) {
			case 1:
				return new RobotomyRequestForm(target);
			case 2:
				return new ShrubberyCreationForm(target);
			case 3:
				return new PresidentialPardonForm(target);
		}
	}
	std::cout << RED << "The form " << name << " cannot be created!" << RESET << std::endl;
	return nullptr;
}

