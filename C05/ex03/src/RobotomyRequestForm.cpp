/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:15:51 by vduchi            #+#    #+#             */
/*   Updated: 2024/01/23 17:28:32 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Colors.hpp"
#include "../inc/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("NoTarget") {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & rhs) : \
	AForm(rhs.getName(), rhs.getGradeSign(), rhs.getGradeExecute()), _target(rhs.getTarget())
{
	*this = rhs;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm & rhs)
{
	this->setSigned(rhs.getSigned());
	return *this;
}

std::ostream& operator<<(std::ostream & os, const RobotomyRequestForm & other)
{
	os << other.getName() << ": \n\t-> grade to sign: " << other.getGradeSign() << std::endl;
	os << "\t-> grade to execute: " << other.getGradeExecute() << std::endl;
	os << "\t-> is signed: " << other.getSigned() << std::endl;
	return os;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : \
	AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

const std::string RobotomyRequestForm::getTarget() const
{
	return this->_target;
}

void RobotomyRequestForm::execute(const Bureaucrat & executor) const
{
	if (this->getSigned() == false)
		throw AForm::FormNotSignedException(this->getName());
	else if (executor.getGrade() > this->getGradeExecute())
		throw AForm::FormExecutedException(executor.getName() + " grade too low. " + this->getName());
	std::cout << BLUE << "Drill" << std::flush;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "." << std::flush;
		usleep(500000);
	}
	int random = rand() % 10 + 1;
	std::cout << RESET << std::endl;
	if (random > 5)
		std::cout << MAGENTA << this->getTarget() << " has been robotomized!" << RESET << std::endl;
	else
		std::cout << MAGENTA << "Robotomization failed for " << this->getTarget() << "!" << RESET << std::endl;
}

