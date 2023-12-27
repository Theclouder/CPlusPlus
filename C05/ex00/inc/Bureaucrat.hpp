/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 12:41:25 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/27 14:53:40 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{

	private:
		const std::string _name;
		int _grade;
	
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &);
		Bureaucrat(const std::string &);
		Bureaucrat(const std::string &, const int);
		Bureaucrat& operator=(const Bureaucrat &);
		~Bureaucrat();

		int getGrade() const;
		const std::string getName() const;
		void gradeUp();
		void gradeDown();
		std::string GradeTooLowException() throw();
		std::string GradeTooHighException() throw();
};

std::ostream& operator<<(std::ostream & os, const Bureaucrat & data);

#endif

