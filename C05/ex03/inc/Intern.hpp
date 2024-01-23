/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:34:05 by vduchi            #+#    #+#             */
/*   Updated: 2024/01/23 17:54:08 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <map>
#include "AForm.hpp"
#include "Colors.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{

	public:
		Intern();
		Intern(const Intern &);
		Intern& operator=(const Intern &);
		~Intern();
		AForm *makeForm(const std::string, const std::string) const;

};

#endif

