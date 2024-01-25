/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:57:44 by vduchi            #+#    #+#             */
/*   Updated: 2024/01/25 11:57:55 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"
#include "../inc/Base.hpp"
#include "../inc/Colors.hpp"

Base::~Base() {}

Base* Base::generate()
{
	int val;
	srand(time(0));
	int max = rand() % 10;
	for (int i = 0; i < max; i++)
		val = rand() % 33;
	if (val < 12)
		return new A();
	else if (val < 23)
		return new B();
	else
		return new C();
}

void Base::identify(Base* p)
{
	std::cout << CYAN << "Identifying with pointer..." << RESET << std::endl;
	if (dynamic_cast<A*>(p) != 0)
		std::cout << GREEN << "It is of classes A" << RESET << std::endl;
	else if (dynamic_cast<B*>(p) != 0)
		std::cout << GREEN << "It is of classes B" << RESET << std::endl;
	else if (dynamic_cast<C*>(p) != 0)
		std::cout << GREEN << "It is of classes C" << RESET << std::endl;
	else
		std::cout << ORANGE << "It is of another class" << RESET << std::endl;
}

void Base::identify(Base& p)
{
	std::cout << CYAN << "Identifying with reference..." << RESET << std::endl;
	try {
		Base& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << GREEN << "It is of classes A" << RESET << std::endl;
	}
	catch (std::bad_cast & ex) {
		try {
			Base& b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << GREEN << "It is of classes B" << RESET << std::endl;
		}
		catch (std::bad_cast & ex) {
			try {
				Base& c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << GREEN << "It is of classes C" << RESET << std::endl;
			}
			catch (std::bad_cast & ex) {
				std::cout << ORANGE << "It is of another class" << RESET << std::endl;
			}
		}
	}
}
