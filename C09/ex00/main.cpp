/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:15:51 by vduchi            #+#    #+#             */
/*   Updated: 2024/01/28 22:55:50 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int fileError(std::string err, int i, std::string err2)
{
	std::cout << RED << err << i << err2 << RESET << std::endl;
	return 1;
}

int retError(std::string err)
{
	std::cout << RED << err << RESET << std::endl;
	return 1;
}

void getBtcDate(const std::string & key, int *arr)
{
	arr[0] = std::atoi(std::string(key, 0, 4).c_str());
	arr[1] = std::atoi(std::string(key, 5, 2).c_str());
	arr[2] = std::atoi(std::string(key, 8, key.length() - 8).c_str());
}

int getStrings(std::string & line, std::string & date, std::string & value, int i)
{
	std::stringstream ss(line);
	if (line.find('|') == std::string::npos)
		return fileError("Line ", i, " has no pair date | value!");
	getline(ss, date, '|');
	getline(ss, value, '|');
	if (value.compare("") == 0)
		return fileError("Line ", i, " has no pair date | value!");
	date = std::string(date, 0, date.length() - 1);
	value = std::string(value, 1, value.length());
	return 0;
}

int checkOneValue(std::string & value)
{
	size_t point = value.find('.');
	if (value.find('.', point + 1) != std::string::npos)
		return 1;
	for (size_t i = 0; i < value.length(); i++)
		if (!isdigit(value[i]) && i != point)
			return 1;
	return 0;
}

int checkDate(std::string & date)
{
	int a[3];
	int l = 0;
	if (date[4] != '-' || date[7] != '-' || date.find("-", 8) != std::string::npos)
		return 1;
	for (; l < 4; l++)
		if (!isdigit(date[l]))
			return 1;
	l++;
	for (; l < 7; l++)
		if (!isdigit(date[l]))
			return 1;
	l++;
	for (; l < (int)date.length(); l++)
		if (!isdigit(date[l]))
			return 1;
	getBtcDate(date, a);
	if (a[1] > 12 || (a[2] > 31 && (a[1] == 1 || a[1] == 3 || a[1] == 5 || a[1] == 7
			|| a[1] == 10 || a[1] == 12)) || (a[2] > 30 && (a[1] == 4 || a[1] == 6
			|| a[1] == 9 || a[1] == 11)) || (a[2] > 28 && a[1] == 2))
			return 1;
	return 0;
}

int checkValues(std::ifstream & in)
{
	int i = 2;
	std::string line, date, value, number;
	getline(in, line);
	while (getline(in, line))
	{
		if (getStrings(line, date, value, i))
			return 1;
		if (checkDate(date))
			return fileError("Date at line ", i, " not correct!");
		if (checkOneValue(value))
			return fileError("Value at line ", i, " not correct!");
		std::cout << CYAN << "Date: -" << date << "-" << std::endl;
		std::cout << "Value: -" << value << "-" << std::endl;
		std::cout << RESET << std::endl;
		i++;
	}
	return 0;
}

int checkFile(char *str)
{
	if (strcmp(str, ".data.csv") == 0)
		return retError("Cannot use database file!");
	std::ifstream in(str);
	if (!in.good())
		return retError("File doesn't exist or not enough permissions!");
	if (checkValues(in))
	{
		in.close();
		return 1;
	}
	in.close();
	return 0;
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
		BitcoinExchange bte;
		std::string line, date, value;
		std::ifstream in(argv[1]);
		getline(in, line);
		while (getline(in, line))
		{
			int a[3];
			int aGood[3];
			int check[3];
			getStrings(line, date, value, 0);
			getBtcDate(date, a);
			std::map<std::string, float>::iterator it = bte.getBegin();
			std::map<std::string, float>::iterator good = bte.getBegin();
			getBtcDate(good->first, aGood);
			for (; it != bte.getEnd(); it++)
			{
				getBtcDate(it->first, check);
//				std::cout << "A 0: -" << a[0] << "- 1:-" << a[1] << "- 2:-" << a[2] << std::endl;
//				std::cout << "Good 0: -" << aGood[0] << "- 1:-" << aGood[1] << "- 2:-" << aGood[2] << std::endl;
//				std::cout << "Check 0: -" << check[0] << "- 1:-" << check[1] << "- 2:-" << check[2] << std::endl;
//				std::cout << "Difference: year:-" << std::abs(check[0] - a[0]) << "- good:-" << std::abs(aGood[0] - a[0]) << std::endl;
//				std::cout << "Difference: month:-" << std::abs(check[1] - a[1]) << "- good:-" << std::abs(aGood[1] - a[1]) << std::endl;
//				std::cout << "Difference: day:-" << std::abs(check[2] - a[2]) << "- good:-" << std::abs(aGood[2] - a[2]) << std::endl << std::endl;
				if (std::abs(check[0] - a[0]) < std::abs(aGood[0] - a[0])
					|| std::abs(check[1] - a[1]) < std::abs(aGood[1] - a[1])
					|| (std::abs(check[1] - a[1]) <= std::abs(aGood[1] - a[1]) && std::abs(check[2] - a[2]) < std::abs(aGood[2] - a[2])))
				{
					good = it;
					getBtcDate(good->first, aGood);
				}
			}
			std::cout << GREEN << "Date: -" << aGood[0] << "-" << aGood[1] << "-" << aGood[2] << "-" << std::endl;
			std::cout << "Value: -" << good->second << "-" << std::endl;
			std::cout << RESET << std::endl;
		}
	}
	catch (std::exception & ex) { std::cout << ex.what() << std::endl; }
}
