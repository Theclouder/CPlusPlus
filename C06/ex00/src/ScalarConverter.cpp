/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:26:14 by vduchi            #+#    #+#             */
/*   Updated: 2024/01/23 19:11:41 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

bool ScalarConverter::ifChar(const std::string & input)
{
	return false;
}

bool ScalarConverter::ifInt(const std::string & input)
{
	return false;
}

bool ScalarConverter::ifFloat(const std::string & input)
{
	return false;
}

bool ScalarConverter::ifDouble(const std::string & input)
{
	return false;
}

void ScalarConverter::convert(const std::string & input)
{
	bool checkType;
	bool (*typeFuncs[])(const std::string &) = { \
		&ScalarConverter::ifChar,
		&ScalarConverter::ifInt,
		&ScalarConverter::ifFloat,
		&ScalarConverter::ifDouble };
	bool (*convFuncs[])(const std::string &) = { \
		&ScalarConverter::ifChar,
		&ScalarConverter::ifInt,
		&ScalarConverter::ifFloat,
		&ScalarConverter::ifDouble };
}
