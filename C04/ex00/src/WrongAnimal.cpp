/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:45:30 by vduchi            #+#    #+#             */
/*   Updated: 2023/09/15 19:36:01 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal") { std::cout << "WrongAnimal default constructor called" << std::endl; }

WrongAnimal::WrongAnimal(std::string type) : _type(type) { std::cout << "WrongAnimal custom constructor called" << std::endl; }

WrongAnimal::WrongAnimal(const WrongAnimal &cpy) : _type(cpy.getType()) { std::cout << "WrongAnimal copy constructor called" << std::endl; }

WrongAnimal::~WrongAnimal(void) { std::cout << "WrongAnimal destructor called" << std::endl; }

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &cpy)
{
	this->setType(cpy.getType());
	std::cout << "WrongAnimal assignment operator called" << std::endl;
	return *this;
}

void WrongAnimal::makeSound() const { std::cout << "WrongAnimal sound!" << std::endl; }

std::string WrongAnimal::getType(void) const { return this->_type; }

void WrongAnimal::setType(std::string type) { this->_type = type; }

