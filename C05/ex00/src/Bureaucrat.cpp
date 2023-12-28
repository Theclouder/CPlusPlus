/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 12:41:00 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/28 16:39:45 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("NoName"), _grade(75) {}

Bureaucrat::Bureaucrat(const Bureaucrat & other) { *this = other; }

Bureaucrat::Bureaucrat(const std::string & name) : _name(name), _grade(75) {}

Bureaucrat::Bureaucrat(const std::string & name, const unsigned int grade) : _name(name), _grade(grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat & other)
{
	this->_grade = other.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat() {}

int Bureaucrat::getGrade() const { return this->_grade; }

const std::string  Bureaucrat::getName() const { return this->_name; }

std::ostream& operator<<(std::ostream & os, const Bureaucrat & other)
{
	os << other.getName();
	return os;
}

void Bureaucrat::gradeUp()
{
	std::cout << "Grading up..." << std::endl;
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException("");
//		std::cout << "Grade already at maximum" << std::endl;
	else
		this->_grade -= 1;
	std::cout << "Now " << *this << "has a grade of " << this->getGrade() << std::endl;
}

void Bureaucrat::gradeDown()
{
	std::cout << "Grading down..." << std::endl;
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException("");
//		std::cout << "Grade already at maximum" << std::endl;
	else
		this->_grade += 1;
	std::cout << "Now " << *this << "has a grade of " << this->getGrade() << std::endl;
}

Bureaucrat::GradeTooLowException::GradeTooLowException (std::string msg) : std::out_of_range(msg + "Grade too low!") {}

Bureaucrat::GradeTooHighException::GradeTooHighException (std::string msg) : std::out_of_range(msg + "Grade too high!") {}
