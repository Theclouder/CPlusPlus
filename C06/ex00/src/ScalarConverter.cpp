/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:26:14 by vduchi            #+#    #+#             */
/*   Updated: 2024/01/25 10:42:38 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter & rhs)
{
	*this = rhs;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter & rhs)
{
	(void)rhs;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

void printOutput(t_vars & vars)
{
	vars.res_i = vars.s_i.str();
	vars.res_c = vars.s_c.str();
	if (vars.s_f.str().find('.') == std::string::npos
		&& vars.s_f.str().compare("inf") != 0 && vars.s_d.str().compare("-inf") != 0)
		vars.s_f << ".0";
	vars.s_f << "f";
	vars.res_f = vars.s_f.str();
	if (vars.s_d.str().find('.') == std::string::npos
		&& vars.s_d.str().compare("inf") != 0 && vars.s_d.str().compare("-inf") != 0)
		vars.s_d << ".0";
	vars.res_d = vars.s_d.str();
	std::cout << "char: " << vars.res_c << std::endl;
	std::cout << "int: " << vars.res_i << std::endl;
	std::cout << "float: " << vars.res_f << std::endl;
	std::cout << "double: " << vars.res_d << std::endl;
}

void ScalarConverter::setVars(t_vars & vars, const std::string & input)
{
	vars.i = 0;
	vars.c = 0;
	vars.f = 0.0f;
	vars.d = 0.0;
	vars.str = input.c_str();
}

int ScalarConverter::printUnknown(int i)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible"  << std::endl;
	if (i < 2)
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else if (i >= 2 && i < 4)
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	return 0;
}

void ScalarConverter::convertChar(const std::string & input)
{
	t_vars vars;
	ScalarConverter::setVars(vars, input);
	vars.c = input[0];
	if (!isprint(vars.c))
		vars.s_c << "Not displayable!";
	else
		vars.s_c << vars.c;
	vars.s_i << static_cast<int>(vars.c);
	vars.s_f << static_cast<float>(vars.c);
	vars.s_d << static_cast<double>(vars.c);
	printOutput(vars);
}

void ScalarConverter::convertInt(const std::string & input)
{
	double d;
	t_vars vars;
	
	ScalarConverter::setVars(vars, input);
	d = std::strtod(vars.str, NULL);
	if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
	{
		vars.s_i << "Overflow/Underflow!";
		vars.s_c << "Overflow/Underflow!";
		vars.s_f << static_cast<float>(d);
		vars.s_d << static_cast<double>(d);
	}
	else
	{
		vars.s_i << atoi(vars.str);
		if (d > std::numeric_limits<char>::max() || d < std::numeric_limits<char>::min())
			vars.s_c << "Overflow/Underflow!";
		else
		{
			vars.c = static_cast<char>(d);
			if (!isprint(vars.c))
				vars.s_c << "Not displayable!";
			else
				vars.s_c << vars.c;
		}
		vars.s_f << static_cast<float>(d);
		vars.s_d << static_cast<double>(d);
	}
	printOutput(vars);
}

void ScalarConverter::convertFloat(const std::string & input)
{
	double d;
	t_vars vars;

	ScalarConverter::setVars(vars, input);
	d = atof(vars.str);
	if (d > std::numeric_limits<float>::max() || d < std::numeric_limits<float>::min())
	{
		vars.s_i << "Overflow/Underflow!";
		vars.s_c << "Overflow/Underflow!";
		vars.s_f << "Overflow/Underflow!";
		vars.s_d << static_cast<double>(d);
	}
	else
	{
		if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
			vars.s_i << "Overflow/Underflow!";
		else
			vars.s_i << static_cast<int>(d);
		if (d > std::numeric_limits<char>::max() || d < std::numeric_limits<char>::min())
			vars.s_c << "Overflow/Underflow!";
		else
		{
			vars.c = static_cast<char>(d);
			if (!isprint(vars.c))
				vars.s_c << "Not displayable!";
			else
				vars.s_c << vars.c;
		}
		vars.s_f << static_cast<float>(d);
		vars.s_d << static_cast<double>(d);
	}
	printOutput(vars);
}

void ScalarConverter::convertDouble(const std::string & input)
{
	t_vars vars;

	ScalarConverter::setVars(vars, input);
	vars.d = atof(vars.str);
	vars.s_d << static_cast<double>(vars.d);
	if (vars.d > std::numeric_limits<float>::max() || vars.d < std::numeric_limits<float>::min())
	{
		vars.s_i << "Overflow/Underflow!";
		vars.s_c << "Overflow/Underflow!";
		vars.s_f << "Overflow/Underflow!";
	}
	else
	{
		if (vars.d > std::numeric_limits<int>::max() || vars.d < std::numeric_limits<int>::min())
			vars.s_i << "Overflow/Underflow!";
		else
			vars.s_i << static_cast<int>(vars.d);
		if (vars.d > std::numeric_limits<char>::max() || vars.d < std::numeric_limits<char>::min())
			vars.s_c << "Overflow/Underflow!";
		else
		{
			vars.c = static_cast<char>(vars.d);
			if (!isprint(vars.c))
				vars.s_c << "Not displayable!";
			else
				vars.s_c << vars.c;
		}
		vars.s_f << static_cast<float>(vars.d);
		vars.s_d << static_cast<double>(vars.d);
	}
	printOutput(vars);
}

bool ScalarConverter::ifChar(const std::string & input)
{
	if (input.length() == 1 && isalpha(input[0]))
	{
		ScalarConverter::convertChar(input);
		return true;
	}
	return false;
}

bool ScalarConverter::ifInt(const std::string & input)
{
	if (input.find('.') != std::string::npos)
		return false;
	for (std::size_t i = 0; i < input.length(); i++)
		if ((i == 0 && (!isdigit(input[i]) && input[i] != '-' && input[i] != '+'))
			|| (i != 0 && !isdigit(input[i])))
		return false;	
	ScalarConverter::convertInt(input);
	return true;
}

bool ScalarConverter::ifFloat(const std::string & input)
{
	std::size_t last = input.length() - 1;
	std::size_t point = input.find('.');
	if (point == std::string::npos || input.find('.', point + 1) != std::string::npos)
		return false;
	for (std::size_t i = 0; i < input.length(); i++)
	{
		if (i == 0 && !isdigit(input[i]) && input[i] != '-' && input[i] != '+')
			return false;
		else if (i == point)
			continue;
		else if (i != 0 && !isdigit(input[i]) && (i != last || (i == last && input[i] != 'f')))
			return false;
	}
	ScalarConverter::convertFloat(input);
	return true;
}

bool ScalarConverter::ifDouble(const std::string & input)
{
	std::size_t point = input.find('.');
	if (point == std::string::npos || input.find('.', point + 1) != std::string::npos)
		return false;
	for (std::size_t i = 0; i < input.length(); i++)
	{
		if (i == 0 && !isdigit(input[i]) && input[i] != '-' && input[i] != '+')
			return false;
		else if (i == point)
			continue;
		else if (i != 0 && !isdigit(input[i]))
			return false;
	}
	ScalarConverter::convertDouble(input);
	return true;
}

int ScalarConverter::convert(const std::string & input)
{
	int i;
	bool (*typeFuncs[])(const std::string &) = { \
		&ScalarConverter::ifChar,
		&ScalarConverter::ifInt,
		&ScalarConverter::ifFloat,
		&ScalarConverter::ifDouble
	};
	for (i = 0; i < 4; i++)
		if (typeFuncs[i](input))
			return 1;
	for (i = 0; i < 6; i++)
	{
		if (unknown[i].compare(input) == 0)
			return ScalarConverter::printUnknown(i);
	}
	std::cout << RED << "Conversion not possible!" << RESET << std::endl;
	return 0;
}
