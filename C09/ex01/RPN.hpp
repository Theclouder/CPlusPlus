/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:44:29 by vduchi            #+#    #+#             */
/*   Updated: 2024/01/29 11:19:50 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

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

#include <stack>
#include <sstream>
#include <cstdlib>
#include <iostream>

class RPN
{
	private:
		std::stack<int> _stack;

	public:
		RPN();
		RPN(const RPN &);
		RPN& operator=(const RPN &);
		~RPN();

		int popStack();
		void pushStack(int);
};

#endif

