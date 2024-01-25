/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:56:33 by vduchi            #+#    #+#             */
/*   Updated: 2024/01/25 11:43:52 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"
#include "../inc/Base.hpp"
#include "../inc/Colors.hpp"

int main()
{
	{
		A test;
		B test2;
		C test3;
		Base gen;
		std::cout << MAGENTA << "Pointers" << std::endl;
		Base* first = gen.generate();
		gen.identify(first);
		Base* second = gen.generate();
		gen.identify(second);
		Base* third = gen.generate();
		gen.identify(third);
		Base* fourth = gen.generate();
		gen.identify(fourth);
		std::cout << std::endl;
		std::cout << MAGENTA << "References" << std::endl;
		gen.identify(test);
		gen.identify(test3);
		gen.identify(test2);
		delete first;
		delete second;
		delete third;
		delete fourth;
	}
}
