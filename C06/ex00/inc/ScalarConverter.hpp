/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:25:32 by vduchi            #+#    #+#             */
/*   Updated: 2024/01/24 17:13:45 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <sstream>

const static std::string unknown[] = {
	"-inff",
	"-inf",
	"+inff",
	"+inf",
	"nanf",
	"nan",
};

typedef struct s_vars
{
	int i;
	char c;
	float f;
	double d;
	const char *str;
	std::string res_i;
	std::string res_c;
	std::string res_f;
	std::string res_d;
	std::stringstream s_i;
	std::stringstream s_c;
	std::stringstream s_f;
	std::stringstream s_d;
} t_vars;

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &);
		ScalarConverter& operator=(const ScalarConverter &);
		~ScalarConverter();
		static int printUnknown(int);
		static bool ifChar(const std::string &);
		static bool ifInt(const std::string &);
		static bool ifFloat(const std::string &);
		static bool ifDouble(const std::string &);
		static void convertChar(const std::string &);
		static void convertInt(const std::string &);
		static void convertFloat(const std::string &);
		static void convertDouble(const std::string &);
		static void setVars(t_vars &, const std::string &);

	public:
		static int convert(const std::string &);
};

#endif

