/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:42:14 by vduchi            #+#    #+#             */
/*   Updated: 2023/10/16 18:32:09 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H__
#define DOG_H__

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal
{

public:
	Dog(void);
	Dog(const Dog &);
	~Dog(void);
	Dog &operator=(const Dog &);

	void makeSound() const;
};

#endif

