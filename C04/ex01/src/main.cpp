/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:55:31 by vduchi            #+#    #+#             */
/*   Updated: 2023/10/16 18:14:46 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
	int i, j;
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();
	Animal *arr[10];

	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	dog->makeSound();
	cat->makeSound(); // will output the cat sound!
	std::cout << std::endl;

	for (i = 0; i < 5; i++)
	{
		arr[i] = new Dog();
		arr[i]->setIdeas("Dog idea no. " + i);
	}
	for (i = 5; i < 10; i++)
	{
		arr[i] = new Cat();
		arr[i]->setIdeas("Cat idea no. " + i);
	}
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 3; j++)
			std::cout << arr[i]->getIdeas()[i] << std::endl;
	}
}
