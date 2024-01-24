/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:30:41 by vduchi            #+#    #+#             */
/*   Updated: 2024/01/24 11:27:30 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Colors.hpp"
#include "../inc/ScalarConverter.hpp"

int main(int ac, char *ag[])
{
	if (ac == 2)
	{
		std::string input(ag[1]);
		ScalarConverter::convert(input);
	}
	else
		std::cout << ORANGE << "Only one argument allowed!" << RESET << std::endl;
}
