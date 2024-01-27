/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:45:37 by vduchi            #+#    #+#             */
/*   Updated: 2024/01/27 17:36:34 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <list>
#include <cstdlib>
#include <iostream>
#include "Colors.hpp"

class Span
{
	private:
		unsigned int _curr;
		const unsigned int _max;
		std::list<unsigned int> _list;
		Span();

	public:
		Span(const unsigned int);
		Span(const Span &);
		Span& operator=(const Span &);
		~Span();

		void setCurr(int);
		unsigned int getCurr() const;
		unsigned int getMax() const;

		void printList();
		void addNumber(int);
		void addMultipleNumbers(int);
		unsigned int longestSpan();
		unsigned int shortestSpan();
		class TooManyElementsException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		} e_oof;
		class NotEnoughElementsException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		} e_nee;
};

#endif

