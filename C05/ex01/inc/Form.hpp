/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:15:22 by vduchi            #+#    #+#             */
/*   Updated: 2024/01/23 12:24:51 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeSign;
		const int _gradeExecute;


	public:
		Form();
		Form(const Form &);
		Form(const std::string, const int, const int);
		Form& operator=(const Form &);
		~Form();

		const std::string getName() const;
		bool getSigned() const;
		int getGradeSign() const;
		int getGradeExecute() const;
		
		void setSigned(const bool);
		void beSigned(const Bureaucrat &);
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
		class FormSignedException : public std::logic_error
		{
			public:
				FormSignedException(std::string msg);
		};

};

std::ostream& operator<<(std::ostream & os, const Form & data);

#endif

