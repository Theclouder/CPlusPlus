/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:15:22 by vduchi            #+#    #+#             */
/*   Updated: 2024/01/23 16:56:11 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string);
		RobotomyRequestForm(const RobotomyRequestForm &);
		RobotomyRequestForm& operator=(const RobotomyRequestForm &);
		~RobotomyRequestForm();

		const std::string getTarget() const;
		void execute(const Bureaucrat &) const;

};

#endif

