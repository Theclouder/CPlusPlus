/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 12:41:00 by vduchi            #+#    #+#             */
/*   Updated: 2024/01/23 17:27:35 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("NoName"), _grade(75) {}

Bureaucrat::Bureaucrat(const Bureaucrat & other) { *this = other; }

Bureaucrat::Bureaucrat(const std::string & name) : _name(name), _grade(75) {}

Bureaucrat::Bureaucrat(const std::string & name, const unsigned int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException(name + " -> ");
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException(name + " -> ");
	this->_grade = grade;
}

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
	os << other.getName() << ", bureaucrat grade " << other.getGrade() << "." << std::endl;
	return os;
}

void Bureaucrat::gradeUp()
{
	std::cout << YELLOW << "Grading up..." << RESET << std::endl;
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException(this->getName() + " -> ");
	else
		this->_grade -= 1;
	std::cout << GREEN << "Now " << this->getName() << " has a grade of " << this->getGrade() << RESET << std::endl;
}

void Bureaucrat::gradeDown()
{
	std::cout << YELLOW << "Grading down..." << RESET << std::endl;
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException(this->getName() + " -> ");
	else
		this->_grade += 1;
	std::cout << GREEN << "Now " << this->getName() << " has a grade of " << this->getGrade() << RESET << std::endl;
}

void Bureaucrat::signForm(AForm & f)
{
	try { f.beSigned(*this); }
	catch (std::exception & ex)
	{
		std::cout << RED << this->getName() << " couldn't sign " << f.getName();
		std::cout << " because " << ex.what() << "." << RESET << std::endl;
		return ;
	}
	std::cout << GREEN << this->getName() << " signed " << f.getName() << RESET << std::endl;
}

void Bureaucrat::executeForm(const AForm & form)
{
	try
	{
		form.execute(*this);
		std::cout << GREEN << this->getName() << " executed " << form.getName() << RESET << std::endl << std::endl;
	}
	catch (std::exception & ex)
	{
		std::cout << RED << ex.what() << std::endl;
	}
}

Bureaucrat::GradeTooLowException::GradeTooLowException (std::string msg) : std::out_of_range(msg + "Grade too low!") {}

Bureaucrat::GradeTooHighException::GradeTooHighException (std::string msg) : std::out_of_range(msg + "Grade too high!") {}
