/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:15:51 by vduchi            #+#    #+#             */
/*   Updated: 2024/01/29 09:31:38 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

float getValue(const std::string & value)
{
	const char *str = value.c_str();
	return atof(str);
}

void getIntDate(const std::string & key, int *arr)
{
	arr[0] = std::atoi(std::string(key, 0, 4).c_str());
	arr[1] = std::atoi(std::string(key, 5, 2).c_str());
	arr[2] = std::atoi(std::string(key, 8, key.length() - 8).c_str());
}

int getStrings(std::string & line, std::string & date, std::string & value, int i)
{
	try {
		std::stringstream ss(line);
		if (line.find('|') == std::string::npos)
			throw std::invalid_argument(" has no pair date | value!");
		getline(ss, date, '|');
		getline(ss, value, '|');
		if (value.compare("") == 0)
			throw std::invalid_argument(" has no pair date | value!");
		date = std::string(date, 0, date.length() - 1);
		value = std::string(value, 1, value.length());
	}
	catch (std::exception & ex) { std::cout << RED << "Line " << i << ex.what() << RESET << std::endl; return 1;} 
	return 0;
}

int checkValue(std::string & value)
{
	try {
		size_t minus = value.find('-');
		if (minus != std::string::npos)
			throw std::invalid_argument("number not positive!");
		size_t point = value.find('.');
		if (value.find('.', point + 1) != std::string::npos)
			throw std::invalid_argument("not a number!");
		for (size_t i = 0; i < value.length(); i++)
			if (!isdigit(value[i]) && i != point)
				throw std::invalid_argument("not a number!");
	}
	catch (std::exception & ex) { std::cout << RED << "Error => " << ex.what() << RESET << std::endl; return 1;}
	return 0;
}

int checkDate(std::string & date)
{
	try {
		int a[3];
		int l = 0;
		if (date[4] != '-' || date[7] != '-' || date.find("-", 8) != std::string::npos)
			throw std::invalid_argument("bad date!");
		for (; l < 4; l++)
			if (!isdigit(date[l]))
				throw std::invalid_argument("not a date!");
		l++;
		for (; l < 7; l++)
			if (!isdigit(date[l]))
				throw std::invalid_argument("not a date!");
		l++;
		for (; l < (int)date.length(); l++)
			if (!isdigit(date[l]))
				throw std::invalid_argument("not a date!");
		getIntDate(date, a);
		if (a[1] > 12 || (a[2] > 31 && (a[1] == 1 || a[1] == 3 || a[1] == 5 || a[1] == 7
				|| a[1] == 10 || a[1] == 12)) || (a[2] > 30 && (a[1] == 4 || a[1] == 6
				|| a[1] == 9 || a[1] == 11)) || (a[2] > 28 && a[1] == 2))
				throw std::invalid_argument("date overflow!");
	}
	catch (std::exception & ex) { std::cout << RED << "Error => " << ex.what() << RESET << std::endl; return 1;}
	return 0;
}

int checkFile(char *str)
{
	try {
		if (strcmp(str, ".data.csv") == 0)
			throw std::invalid_argument("Cannot use database file!");
		std::ifstream in(str);
		if (!in.good())
			throw std::invalid_argument("File doesn't exist or not enough permissions!");
		in.close();
	}
	catch (std::exception & ex) { std::cout << RED << ex.what() << RESET << std::endl; return 1; }
	return 0;
}

void loop(BitcoinExchange bte, std::string & value, int *a)
{
	int check[3];
	int aGood[3];
	std::map<std::string, float>::iterator it = bte.getBegin();
	std::map<std::string, float>::iterator good = bte.getBegin();
	getIntDate(good->first, aGood);
	for (; it != bte.getEnd(); it++)
	{
		getIntDate(it->first, check);
		if (std::abs(check[0] - a[0]) < std::abs(aGood[0] - a[0])
			|| std::abs(check[1] - a[1]) < std::abs(aGood[1] - a[1])
			|| (std::abs(check[1] - a[1]) <= std::abs(aGood[1] - a[1])
			&& std::abs(check[2] - a[2]) < std::abs(aGood[2] - a[2])
			&& check[2] - a[2] > aGood[2] - a[2] && check[2] - a[2] <= 0))
		{
			good = it;
			getIntDate(good->first, aGood);
		}
	}
	std::cout << aGood[0] << "-" << aGood[1] << "-" << aGood[2];
	float out = getValue(value) * bte.getBtcPrice(good->first);
	std::cout << std::fixed << std::setprecision(2) << " => " << getValue(value) << " = " << out;
	std::cout << RESET << std::endl;
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << ORANGE << "The program accept only one argument, ";
		std::cout << ORANGE << "the name of the database to check";
		std::cout << RESET << std::endl;
		return 1;
	}
	else if (checkFile(argv[1]))
		return 1;
	try {
		int i = 1;
		BitcoinExchange bte;
		std::string line, date, value;
		std::ifstream in(argv[1]);
		getline(in, line);
		while (getline(in, line) && i++)
		{
			int a[3];
			if (getStrings(line, date, value, i) || checkDate(date) || checkValue(value))
				continue ;
			getIntDate(date, a);
			loop(bte, value, a);
		}
	}
	catch (std::exception & ex) { std::cout << ex.what() << std::endl; }
}
