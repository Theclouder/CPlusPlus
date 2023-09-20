/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:45:30 by vduchi            #+#    #+#             */
/*   Updated: 2023/09/15 19:44:56 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") { std::cout << "Cat default constructor called" << std::endl; }

Cat::Cat(const Cat &cpy) : Animal(cpy) { std::cout << "Cat copy constructor called" << std::endl; }

Cat::~Cat(void) { std::cout << "Cat destructor called" << std::endl; }

Cat	&Cat::operator=(const Cat &cpy)
{
	this->setType(cpy.getType());
	std::cout << "Cat assignment operator called" << std::endl;
	return *this;
}

void Cat::makeSound() const { std::cout << "Meow!" << std::endl; }

