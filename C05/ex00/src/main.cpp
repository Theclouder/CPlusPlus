/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:49:58 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/28 16:40:10 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int main()
{
	Bureaucrat test("Valerio", 1);
	try
	{
		test.gradeUp();
		test.gradeDown();
	}
	catch (std::exception & ex)
	{
		std::cout << "Error" << std::endl;
	}
}
