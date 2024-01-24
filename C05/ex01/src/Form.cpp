/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:15:51 by vduchi            #+#    #+#             */
/*   Updated: 2024/01/23 12:44:57 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Colors.hpp"

Form::Form() : _name("Form"), _isSigned(false), _gradeSign(0), _gradeExecute(0) {}

Form::Form(const Form & rhs) : _name(rhs._name), _gradeSign(rhs._gradeSign), _gradeExecute(rhs._gradeExecute)
{
	*this = rhs;
}

Form& Form::operator=(const Form & rhs)
{
	const_cast<std::string&>(this->_name) = rhs.getName();
	const_cast<int&>(this->_gradeSign) = rhs.getGradeSign();
	const_cast<int&>(this->_gradeExecute) = rhs.getGradeExecute();
	this->_isSigned = rhs._isSigned;
	return *this;
}

std::ostream& operator<<(std::ostream & os, const Form & other)
{
	os << other.getName() << ": \t-> grade to sign: " << other.getGradeSign() << std::endl;
	os << "\t-> grade to execute: " << other.getGradeExecute() << std::endl;
	os << "\t-> is signed: " << other.getSigned() << std::endl;
	return os;
}

Form::Form(const std::string name, const int gradeSign, const int gradeExecute) : \
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
	std::cout << GREEN << "Form " << name << " created!" << RESET << std::endl;
}

Form::~Form() {}

const std::string Form::getName() const
{
	return this->_name;
}

bool Form::getSigned() const
{
	return this->_isSigned;
}

int Form::getGradeSign() const
{
	return this->_gradeSign;
}

int Form::getGradeExecute() const
{
	return this->_gradeExecute;
}

void Form::setSigned(const bool isSigned)
{
	this->_isSigned = isSigned;
}

void Form::beSigned(const Bureaucrat & b)
{
	if (b.getGrade() > this->getGradeSign())
		throw Form::GradeTooLowException(b.getName() + " -> ");
	if (this->getSigned() == true)
		throw Form::FormSignedException(this->getName() + " -> ");
	this->setSigned(true);
}

Form::GradeTooLowException::GradeTooLowException (std::string msg) : std::out_of_range(msg + "grade too low!") {}

Form::GradeTooHighException::GradeTooHighException (std::string msg) : std::out_of_range(msg + "grade too high!") {}

Form::FormSignedException::FormSignedException (std::string msg) : std::logic_error(msg + "already signed!") {}

