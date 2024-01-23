/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:15:51 by vduchi            #+#    #+#             */
/*   Updated: 2024/01/23 17:14:13 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Colors.hpp"
#include "../inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("NoTarget") {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & rhs) : \
	AForm(rhs.getName(), rhs.getGradeSign(), rhs.getGradeExecute()), _target(rhs.getTarget())
{
	*this = rhs;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm & rhs)
{
	this->setSigned(rhs.getSigned());
	return *this;
}

std::ostream& operator<<(std::ostream & os, const PresidentialPardonForm & other)
{
	os << other.getName() << ": \n\t-> grade to sign: " << other.getGradeSign() << std::endl;
	os << "\t-> grade to execute: " << other.getGradeExecute() << std::endl;
	os << "\t-> is signed: " << other.getSigned() << std::endl;
	return os;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : \
	AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

const std::string PresidentialPardonForm::getTarget() const
{
	return this->_target;
}

void PresidentialPardonForm::execute(const Bureaucrat & executor) const
{
	if (this->getSigned() == false)
		throw AForm::FormNotSignedException(this->getName());
	else if (executor.getGrade() > this->getGradeExecute())
		throw AForm::FormExecutedException(executor.getName() + " grade too low. " + this->getName());
	std::cout << MAGENTA << this->getTarget() << " has been pardoned by Zaphod Beeblebrox!" << RESET << std::endl;
}
