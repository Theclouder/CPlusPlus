/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:55:31 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/10 14:35:16 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
	int i, j;
	Animal *arr[10];
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();

	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	dog->makeSound();
	cat->makeSound();
	std::cout << std::endl;

	for (i = 0; i < 10; i++)
	{
		char buffer[10];
		sprintf(buffer, "%d", i);
		if (i < 5)
		{
			arr[i] = new Dog();
			std::string idea = "Dog idea no. ";
			arr[i]->setIdeas(idea + buffer);
		}
		else
		{
			arr[i] = new Cat();
			std::string idea = "Cat idea no. ";
			arr[i]->setIdeas(idea + buffer);
		}
	}
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 3; j++)
			std::cout << arr[i]->getIdeas()[i] << std::endl;
	}
	for (i = 0; i < 10; i++)
		delete arr[i];
	delete dog;
	delete cat;
}
