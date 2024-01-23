/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 12:41:25 by vduchi            #+#    #+#             */
/*   Updated: 2024/01/23 11:48:14 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{

	private:
		const std::string _name;
		unsigned int _grade;
	
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &);
		Bureaucrat(const std::string &);
		Bureaucrat(const std::string &, const unsigned int);
		Bureaucrat& operator=(const Bureaucrat &);
		~Bureaucrat();

		int getGrade() const;
		const std::string getName() const;
		void gradeUp();
		void gradeDown();
		void signForm(Form &);
		class GradeTooHighException : public std::out_of_range
		{
			public:
				GradeTooHighException(std::string msg);
		};
		class GradeTooLowException : public std::out_of_range
		{
			public:
				GradeTooLowException(std::string msg);
		};
};

std::ostream& operator<<(std::ostream & os, const Bureaucrat & data);

#endif

