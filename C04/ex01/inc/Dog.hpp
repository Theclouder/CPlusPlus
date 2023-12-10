/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:42:14 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/10 14:23:15 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Brain.hpp"
#include "Animal.hpp"

class Dog : public Animal
{

public:
	Dog();
	Dog(const Dog &);
	~Dog();
	Dog &operator=(const Dog &);

	void makeSound() const;
	void setIdeas(std::string);
	void setIdeas(std::string, int);
	const std::string *getIdeas() const;
	const std::string &getIdeas(int) const;

private:
	Brain *brain;
};

#endif
