/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:45:30 by vduchi            #+#    #+#             */
/*   Updated: 2023/10/16 18:34:46 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat(void) : Animal("Cat")
{
	this->brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &cpy) : Animal(cpy)
{
	*this = cpy;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat(void) { std::cout << "Cat destructor called" << std::endl; }

Cat &Cat::operator=(const Cat &cpy)
{
	this->setType(cpy.getType());
	for (int i = 0; i < 100; i++)
		this->setIdeas(cpy.getIdeas(i), i);
	std::cout << "Cat assignment operator called" << std::endl;
	return *this;
}

void Cat::makeSound() const { std::cout << "Meow!" << std::endl; }

void Cat::setIdeas(std::string newIdea)
{
	this->brain->setIdeas(newIdea);
}

void Cat::setIdeas(std::string newIdea, int idx)
{
	this->brain->setIdeas(newIdea, idx);
}

std::string *Cat::getIdeas() const
{
	return this->brain->getIdeas();
}

std::string &Cat::getIdeas(int idx) const
{
	return this->brain->getIdeas(idx);
}

