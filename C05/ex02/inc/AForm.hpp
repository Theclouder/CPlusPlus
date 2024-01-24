/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:15:22 by vduchi            #+#    #+#             */
/*   Updated: 2024/01/23 15:40:48 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeSign;
		const int _gradeExecute;
		AForm();
		AForm(const AForm &);
		AForm& operator=(const AForm &);

	public:
		AForm(const std::string, const int, const int);
		virtual ~AForm();

		const std::string getName() const;
		bool getSigned() const;
		int getGradeSign() const;
		int getGradeExecute() const;
		
		void setName(const std::string &);
		void setGradeSign(int);
		void setGradeExecute(int);
		void setSigned(const bool);

		void beSigned(const Bureaucrat &);
		virtual void execute(const Bureaucrat &) const = 0;
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
		class FormNotSignedException : public std::logic_error
		{
			public:
				FormNotSignedException(std::string msg);
		};
		class FormExecutedException : public std::logic_error
		{
			public:
				FormExecutedException(std::string msg);
		};

};

std::ostream& operator<<(std::ostream & os, const AForm & data);

#endif

