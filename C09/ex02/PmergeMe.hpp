/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:43:03 by vduchi            #+#    #+#             */
/*   Updated: 2024/01/29 14:54:06 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

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

#include <list>
#include <vector>
#include <iostream>

class PmergeMe
{
	private:
		std::list<int> _l;
		std::vector<int> _v;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &);
		PmergeMe& operator=(const PmergeMe &);
		~PmergeMe();

};

#endif

