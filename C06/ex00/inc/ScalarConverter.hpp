/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:25:32 by vduchi            #+#    #+#             */
/*   Updated: 2024/01/24 11:26:04 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>

const static std::string unknown[] = {
	"-inff",
	"+inff",
	"nanf",
	"-inf",
	"+inf",
	"nan",
};

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &);
		ScalarConverter& operator=(const ScalarConverter &);
		~ScalarConverter();
		static int printUnknown(const std::string &, int);
		static bool ifChar(const std::string &);
		static bool ifInt(const std::string &);
		static bool ifFloat(const std::string &);
		static bool ifDouble(const std::string &);
		static void convertChar(const std::string &);
		static void convertInt(const std::string &);
		static void convertFloat(const std::string &);
		static void convertDouble(const std::string &);

	public:
		static int convert(const std::string &);
};

#endif

