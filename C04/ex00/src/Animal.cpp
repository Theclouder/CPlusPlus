/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:45:30 by vduchi            #+#    #+#             */
/*   Updated: 2023/09/15 19:35:42 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("Animal") { std::cout << "Animal default constructor called" << std::endl; }

Animal::Animal(std::string type) : _type(type) { std::cout << "Animal custom constructor called" << std::endl; }

Animal::Animal(const Animal &cpy) : _type(cpy.getType()) { std::cout << "Animal copy constructor called" << std::endl; }

Animal::~Animal(void) { std::cout << "Animal destructor called" << std::endl; }

Animal	&Animal::operator=(const Animal &cpy)
{
	this->setType(cpy.getType());
	std::cout << "Animal assignment operator called" << std::endl;
	return *this;
}

void Animal::makeSound() const { std::cout << "Animal sound!" << std::endl; }

std::string Animal::getType(void) const { return this->_type; }

void Animal::setType(std::string type) { this->_type = type; }

