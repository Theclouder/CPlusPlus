/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:48:05 by vduchi            #+#    #+#             */
/*   Updated: 2024/01/28 22:05:38 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# define RED	"\033[0;31m"
# define GREEN	"\033[0;32m"
# define YELLOW	"\033[0;33m"
# define BLUE	"\x1B[38;2;47;82;191m"
# define MAGENTA	"\033[0;35m"
# define CYAN	"\033[0;36m"
# define ORANGE	"\033[1;31m"
# define WHITE	"\033[0;37m"
# define BLACK	"\x1B[30m"
# define RESET	"\x1B[0m"

#include <map>
#include <cstring>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iostream>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _btcPrice;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &);
		BitcoinExchange& operator=(const BitcoinExchange &);
		~BitcoinExchange();

		typedef std::map<std::string, float>::iterator iter;

		iter getEnd();
		iter getBegin();
		float getBtcPrice(std::string &) const;
		void setBtcPrice(std::string &, float &);
		class DataNotFoundException: public std::exception
		{
			const char *what() const throw();
		} e_dnf;
};

#endif

