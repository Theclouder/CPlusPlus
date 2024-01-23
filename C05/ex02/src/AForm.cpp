/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:15:51 by vduchi            #+#    #+#             */
/*   Updated: 2024/01/23 17:15:18 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Colors.hpp"

AForm::AForm() : _name("AForm"), _isSigned(false), _gradeSign(0), _gradeExecute(0) {}

AForm::AForm(const AForm & rhs) : _name(rhs._name), _gradeSign(rhs._gradeSign), _gradeExecute(rhs._gradeExecute)
{
	*this = rhs;
}

AForm& AForm::operator=(const AForm & rhs)
{
	this->_isSigned = rhs._isSigned;
	return *this;
}

std::ostream& operator<<(std::ostream & os, const AForm & other)
{
	os << other.getName() << ": \t-> grade to sign: " << other.getGradeSign() << std::endl;
	os << "\t-> grade to execute: " << other.getGradeExecute() << std::endl;
	os << "\t-> is signed: " << other.getSigned() << std::endl;
	return os;
}

AForm::AForm(const std::string name, const int gradeSign, const int gradeExecute) : \
	_name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute)
{
	if (gradeSign < 1)
		throw Bureaucrat::GradeTooHighException(name + " -> grade to sign: ");
	else if (gradeSign > 150)
		throw Bureaucrat::GradeTooLowException(name + " -> grade to sign: ");
	if (gradeExecute < 1)
		throw Bureaucrat::GradeTooHighException(name + " -> grade to execute: ");
	else if (gradeExecute > 150)
		throw Bureaucrat::GradeTooLowException(name + " -> grade to execute: ");
	std::cout << ORANGE << "AForm " << name << " created!" << RESET << std::endl;
}

AForm::~AForm() {}

const std::string AForm::getName() const
{
	return this->_name;
}

bool AForm::getSigned() const
{
	return this->_isSigned;
}

int AForm::getGradeSign() const
{
	return this->_gradeSign;
}

int AForm::getGradeExecute() const
{
	return this->_gradeExecute;
}

void AForm::setSigned(const bool isSigned)
{
	this->_isSigned = isSigned;
}

void AForm::beSigned(const Bureaucrat & b)
{
	if (b.getGrade() > this->getGradeSign())
		throw AForm::GradeTooLowException(b.getName() + " -> ");
	if (this->getSigned() == true)
		throw AForm::FormSignedException(this->getName() + " -> ");
	this->setSigned(true);
}

AForm::GradeTooLowException::GradeTooLowException (std::string msg) : std::out_of_range(msg + "grade too low!") {}

AForm::GradeTooHighException::GradeTooHighException (std::string msg) : std::out_of_range(msg + "grade too high!") {}

AForm::FormSignedException::FormSignedException (std::string msg) : std::logic_error(msg + "already signed!") {}

AForm::FormNotSignedException::FormNotSignedException (std::string msg) : std::logic_error(msg + " not signed!") {}

AForm::FormExecutedException::FormExecutedException (std::string msg) : std::logic_error(msg + " cannot be executed!") {}

