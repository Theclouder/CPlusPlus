/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:15:51 by vduchi            #+#    #+#             */
/*   Updated: 2024/01/29 14:49:22 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int checkInput(std::string input)
{
	try {
		int num = 0, op = 0;
		std::string digit;
		std::stringstream ss(input);
		while (getline(ss, digit, ' '))
		{
			for (size_t i = 0; i < digit.length(); i++)
				if (!isdigit(digit[i]) && digit[i] != '/' && digit[i] != '*' && digit[i] != '-' && digit[i] != '+')
					throw std::invalid_argument("argument is not a valid reversed polish notation!");
			if (digit.length() > 1 && (digit[0] == '/' || digit[0] == '*' || digit[0] == '-' || digit[0] == '+'))
				throw std::invalid_argument("argument operator is not valid!");
			if (digit[0] >= '0' && digit[0] <= '9')
				num++;
			else
				op++;
		}
		if (op != num - 1)
			throw std::invalid_argument("number of operators not correct!");
	}
	catch (std::exception & ex) { std::cout << RED << "Error => " << ex.what() << RESET << std::endl; return 1; }
	return 0;
}

void loop(RPN & rpn, std::string & digit)
{
	if (digit[0] >= '0' && digit[0] <= '9')
		rpn.pushStack(std::atoi(digit.c_str()));
	else
	{
		int one = rpn.popStack(), two = rpn.popStack(), res = 0;
		switch (digit[0]) {
			case 43:
				{
					res = two + one;
					break;
				}
			case 45:
				{
					res = two - one;
					break;
				}
			case 42:
				{
					res = two * one;
					break;
				}
			case 47:
				{
					if (one == 0)
						throw std::runtime_error("Attempted division by zero!");
					res = two / one;
					break;
				}
		}
		rpn.pushStack(res);
	}
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << ORANGE << "The program accept only one argument, ";
		std::cout << ORANGE << "the operation that has to be performed";
		std::cout << RESET << std::endl;
		return 1;
	}
	else if (checkInput(std::string(argv[1])))
		return 1;
	try {
		RPN rpn;
		std::string digit, str(argv[1]);
		std::stringstream ss(str);
		while (getline(ss, digit, ' '))
			loop(rpn, digit);
		std::cout << rpn.popStack() << std::endl;
	}
	catch (std::exception & ex) { std::cout << RED << ex.what() << RESET << std::endl; }
}
