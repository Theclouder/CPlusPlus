/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:26:14 by vduchi            #+#    #+#             */
/*   Updated: 2024/01/24 12:51:27 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Colors.hpp"
#include "../inc/ScalarConverter.hpp"

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

void printOutput(const std::string & c, const int & i, const float & f, const double & d)
{
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << std::endl;
	std::cout << "double: " << d << std::endl;
}

int ScalarConverter::printUnknown(const std::string & input, int i)
{
	(void)input;
	(void)i;
	return 1;
}

void ScalarConverter::convertChar(const std::string & input)
{
	int n;
	char c;
	float f;
	double d;
	std::string out;
	c = input[1];
	n = static_cast<int>(c);
	f = static_cast<float>(c);
	d = static_cast<double>(c);
	if (n < 33 || n > 126)
		out = "Not displayable!";
	else
		out = c;
	printOutput(out, n, f, d);
}

void ScalarConverter::convertInt(const std::string & input)
{
	int n;
	char c;
	float f;
	double d;
	std::string out;
	const char *str = input.c_str();
	n = atoi(str);
	c = static_cast<char>(n);
	f = static_cast<float>(n);
	d = static_cast<double>(n);
	if (n < 33 || n > 126)
		out = "Not displayable!";
	else
		out = c;
	printOutput(out, n, f, d);
}

void ScalarConverter::convertFloat(const std::string & input)
{
	int n;
	char c;
	float f;
	double d;
	std::string out;
	f = std::stof(input);
	n = static_cast<int>(f);
	c = static_cast<char>(n);
	d = static_cast<double>(f);
	if (n < 33 || n > 126)
		out = "Not displayable!";
	else
		out = c;
	printOutput(out, n, f, d);
}

void ScalarConverter::convertDouble(const std::string & input)
{
	int n;
	char c;
	float f;
	double d;
	std::string out;
	const char *str = input.c_str();
	d = atof(str);
	n = static_cast<int>(d);
	c = static_cast<char>(n);
	f = static_cast<float>(d);
	if (n < 33 || n > 126)
		out = "Not displayable!";
	else
		out = c;
	printOutput(out, n, f, d);
}

bool ScalarConverter::ifChar(const std::string & input)
{
	if (input.length() == 3 && input[0] == '\'' && input[2] == '\'')
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
	for (i = 0; i < 4; i++)
		if (unknown[i].compare(input) == 0)
			return ScalarConverter::printUnknown(input, i);
	std::cout << RED << "Conversion not possible!" << RESET << std::endl;
	return 0;
}
