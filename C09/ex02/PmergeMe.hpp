/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:43:03 by vduchi            #+#    #+#             */
/*   Updated: 2024/02/23 13:50:53 by vduchi           ###   ########.fr       */
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
#include <iomanip>
#include <iostream>
#include <ctime>
#include <cstdlib>

class PmergeMe
{
	private:
		std::list<int> _l;
		std::vector<int> _v;
		clock_t _beginL, _endL, _beginV, _endV;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &);
		PmergeMe& operator=(const PmergeMe &);
		~PmergeMe();

		void printET(char **);
		int getListEl(std::list<int> &, int);
		void setListEl(std::list<int> &, int, int);
		void startListAlgorithm(char *argv[]);
		void startVectorAlgorithm(char *argv[]);
		void vecMerge(std::vector<int> &, int, int, int);
		void vecMergeSort(std::vector<int> &, int, int);
		void listMerge(std::list<int> &, int, int, int);
		void listMergeSort(std::list<int> &, int, int);
};

#endif

