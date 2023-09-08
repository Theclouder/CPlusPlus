/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:39:02 by vduchi            #+#    #+#             */
/*   Updated: 2023/09/05 09:47:15 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	_funcPtr[0] = &Harl::debug;
	_funcPtr[1] = &Harl::info;
	_funcPtr[2] = &Harl::warning;
	_funcPtr[3] = &Harl::error;
	_arr[0] = "DEBUG";
	_arr[1] = "INFO";
	_arr[2] = "WARNING";
	_arr[3] = "ERROR";
}

Harl::~Harl(void) {}

void Harl::complain(std::string level)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (level.compare(this->_arr[i]) == 0)
			break;
	}
	switch (i)
	{
	case 0:
		(this->*_funcPtr[0])();
	case 1:
		(this->*_funcPtr[1])();
	case 2:
		(this->*_funcPtr[2])();
	case 3:
		(this->*_funcPtr[3])();
	default:
		break;
	}
}

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl
						<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl
						<< std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl
						<< "I cannot believe adding extra bacon costs more money." << std::endl
						<< "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl
						<< std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl
						<< "I think I deserve to have some extra bacon for free." << std::endl
						<< "I’ve been coming for years whereas you started working here since last month." << std::endl
						<< std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl
						<< "This is unacceptable! I want to speak to the manager now." << std::endl
						<< std::endl;
}
