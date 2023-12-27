/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 12:41:00 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/27 14:50:56 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("NoName"), _grade(75) {}

Bureaucrat::Bureaucrat(const Bureaucrat & other) { *this = other; }

Bureaucrat::Bureaucrat(const std::string & name) : _name(name), _grade(75) {}

Bureaucrat::Bureaucrat(const std::string & name, const int grade) : _name(name), _grade(grade) {}

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
	if (this->_grade - 1 < 1)
		std::cout << "Grade already at maximum" << std::endl;
	else
		this->_grade -= 1;
}

void Bureaucrat::gradeDown()
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
//		std::cout << "Grade already at maximum" << std::endl;
	else
		this->_grade += 1;
}

std::string Bureaucrat::GradeTooLowException() throw()
{
	std::string out = "Grade too low!\n";
	return out;
}

std::string Bureaucrat::GradeTooHighException() throw()
{
	std::string out = "Grade too high!\n";
	return out;
}
