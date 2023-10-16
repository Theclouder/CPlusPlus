/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:45:30 by vduchi            #+#    #+#             */
/*   Updated: 2023/10/16 18:27:20 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) { std::cout << "Brain default constructor called" << std::endl; }

Brain::Brain(const Brain &cpy)
{
	*this = cpy;
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain::~Brain(void) { std::cout << "Brain destructor called" << std::endl; }

Brain &Brain::operator=(const Brain &cpy)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = cpy.ideas[i];
	std::cout << "Brain assignment operator called" << std::endl;
	return *this;
}
