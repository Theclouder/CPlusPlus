/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:07:52 by vduchi            #+#    #+#             */
/*   Updated: 2024/01/27 17:44:10 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"
#include "../inc/Colors.hpp"

int main()
{
	{
		try {
			Span s(5);
			s.addNumber(1);
			s.addNumber(2);
			s.addNumber(3);
			s.addNumber(6);
			s.addNumber(7);
			s.addNumber(8);
		} catch (std::exception & ex) { std::cout << ex.what() << RESET << std::endl; }
	}
	std::cout << std::endl;
	{
		try {
			Span s(5);
			s.addNumber(1);
			s.addNumber(3);
			s.addNumber(6);
			s.addNumber(7);
			s.addNumber(10);

			std::cout << MAGENTA << "List items: ";
			s.printList();
			std::cout << RESET << std::endl;
			std::cout << CYAN << "Get longest span: " << RESET;
			std::cout << CYAN << s.longestSpan() << RESET << std::endl;
			std::cout << CYAN << "Get shortest span: " << RESET;
			std::cout << CYAN << s.shortestSpan() << RESET << std::endl;
		} catch (std::exception & ex) { std::cout << ex.what() << RESET << std::endl; }
	}
	std::cout << std::endl;
	{
		try {
			Span s(10000);
			s.addMultipleNumbers(10000);

			std::cout << MAGENTA << "List items: ";
			s.printList();
			std::cout << RESET << std::endl;
			std::cout << CYAN << "Get longest span: " << RESET;
			std::cout << CYAN << s.longestSpan() << RESET << std::endl;
			std::cout << CYAN << "Get shortest span: " << RESET;
			std::cout << CYAN << s.shortestSpan() << RESET << std::endl;
		} catch (std::exception & ex) { std::cout << ex.what() << RESET << std::endl; }
	}
}
