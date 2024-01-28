/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:04:46 by vduchi            #+#    #+#             */
/*   Updated: 2024/01/28 22:27:06 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
//	int i = 0;
	std::ifstream in(".data.csv");
	if (!in.good())
		throw e_dnf;
	std::string tmp, line, date, value;
	getline(in, line);
	while (getline(in, line))
	{
		std::stringstream s(line);
		getline(s, date, ',');
		getline(s, value, ',');
		const char *str = value.c_str();
		float val = atof(str);
		this->setBtcPrice(date, val);
		this->setBtcPrice(date, val);
//		i++;
//		if (i > 30)
//			break;
	}
//	for (std::map<std::string, float>::iterator it = this->_btcPrice.begin(); it != this->_btcPrice.end(); it++)
//	{
//		std::cout << MAGENTA << std::fixed << std::setprecision(2) << "Key -> " << it->first;
//		std::cout << " Value -> " << it->second << RESET << std::endl;
//	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & rhs)
{
	*this = rhs;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange & rhs)
{
	this->_btcPrice = rhs._btcPrice;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}


float BitcoinExchange::getBtcPrice(std::string & ref) const
{
	return this->_btcPrice.at(ref);
}

void BitcoinExchange::setBtcPrice(std::string & key, float & value)
{
	this->_btcPrice[key] = value;
}

BitcoinExchange::iter BitcoinExchange::getEnd() { return this->_btcPrice.end(); }
BitcoinExchange::iter BitcoinExchange::getBegin() { return this->_btcPrice.begin(); }

const char *BitcoinExchange::DataNotFoundException::what() const throw()
{
	return RED "Data file not found! Correct path is .data.csv" RESET;
}
