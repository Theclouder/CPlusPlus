/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:45:30 by vduchi            #+#    #+#             */
/*   Updated: 2023/09/15 19:44:48 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") { std::cout << "Dog default constructor called" << std::endl; }

Dog::Dog(const Dog &cpy) : Animal(cpy) { std::cout << "Dog copy constructor called" << std::endl; }

Dog::~Dog(void) { std::cout << "Dog destructor called" << std::endl; }

Dog	&Dog::operator=(const Dog &cpy)
{
	this->setType(cpy.getType());
	std::cout << "Dog assignment operator called" << std::endl;
	return *this;
}

void Dog::makeSound() const { std::cout << "Bark!" << std::endl; }

