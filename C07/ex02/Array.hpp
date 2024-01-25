/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:02:09 by vduchi            #+#    #+#             */
/*   Updated: 2024/01/25 18:37:18 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

// # Regular Colors
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\x1B[38;2;47;82;191m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define ORANGE "\033[1;31m"
# define WHITE "\033[0;37m"
# define BLACK "\x1B[30m"
# define RESET "\x1B[0m"

#include <iostream>

template <typename T>
class Array
{
	private:
		T* _arr;
		unsigned int _size;

	public:
		Array();
		Array(unsigned int);
		Array(const Array &);
		Array& operator=(const Array &);
		~Array();

		unsigned int size() const;
		class outOfBoundsException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		} e_oob;
    	T& operator[](unsigned int);
};

#endif
