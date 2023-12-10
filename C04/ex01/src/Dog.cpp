/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:45:30 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/10 14:33:06 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog(void) : Animal("Dog")
{
	this->brain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &cpy) : Animal(cpy)
{
	*this = cpy;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog(void)
{
	delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &cpy)
{
	this->setType(cpy.getType());
	for (int i = 0; i < 100; i++)
		this->setIdeas(cpy.getIdeas(i), i);
	std::cout << "Dog assignment operator called" << std::endl;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Bark!" << std::endl;
}

void Dog::setIdeas(std::string newIdea)
{
	this->brain->setIdeas(newIdea);
}

void Dog::setIdeas(std::string newIdea, int idx)
{
	this->brain->setIdeas(newIdea, idx);
}

const std::string *Dog::getIdeas() const
{
	return this->brain->getIdeas();
}

const std::string &Dog::getIdeas(int idx) const
{
	return this->brain->getIdeas(idx);
}

