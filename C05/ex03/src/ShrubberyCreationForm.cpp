/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:15:51 by vduchi            #+#    #+#             */
/*   Updated: 2024/01/23 18:08:43 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Colors.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("NoTarget") {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & rhs) : \
	AForm(rhs.getName(), rhs.getGradeSign(), rhs.getGradeExecute()), _target(rhs.getTarget())
{
	*this = rhs;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm & rhs)
{
	this->setSigned(rhs.getSigned());
	return *this;
}

std::ostream& operator<<(std::ostream & os, const ShrubberyCreationForm & other)
{
	os << other.getName() << ": \n\t-> grade to sign: " << other.getGradeSign() << std::endl;
	os << "\t-> grade to execute: " << other.getGradeExecute() << std::endl;
	os << "\t-> is signed: " << other.getSigned() << std::endl;
	return os;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : \
	AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const std::string ShrubberyCreationForm::getTarget() const
{
	return this->_target;
}

void ShrubberyCreationForm::execute(const Bureaucrat & executor) const
{
	if (this->getSigned() == false)
		throw AForm::FormNotSignedException(this->getName());
	else if (executor.getGrade() > this->getGradeExecute())
		throw AForm::FormExecutedException(executor.getName() + " grade too low. " + this->getName());
	std::ofstream myFile(this->getTarget() + "_shrubbery");
	myFile << "ex02/" << std::endl << "|– Makefile" << std::endl;
	myFile << "|– inc/" << std::endl << "| |– AForm.hpp" << std::endl << "| |– Bureaucrat.hpp" << std::endl;
	myFile << "| |– Colors.hpp" << std::endl << "| |– Intern.hpp" << std::endl;
	myFile << "| |– PresidentialPardonForm.hpp" << std::endl;
	myFile << "| |– RobotoryRequestForm.hpp" << std::endl << "| |– ShrubberyCreationForm.hpp" << std::endl;
	myFile << "|– src/" << std::endl << "| |– AForm.cpp" << std::endl << "| |– Bureaucrat.cpp" << std::endl;
	myFile << "| |– Intern.cpp" << std::endl << "| |– PresidentialPardonForm.cpp" << std::endl;
	myFile << "| |– RobotoryRequestForm.cpp" << std::endl << "| |– ShrubberyCreationForm.cpp" << std::endl;
	myFile.close();
	std::cout << MAGENTA << this->getTarget() << "_shrubbery file created!" << RESET << std::endl;
}

