/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:42:14 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/10 14:23:55 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{

public:
	Animal();
	Animal(std::string);
	Animal(const Animal &);
	virtual ~Animal();
	Animal &operator=(const Animal &);

	void setType(std::string);
	std::string getType() const;
	virtual void makeSound() const;
	virtual void setIdeas(std::string) = 0;
	virtual const std::string *getIdeas() const = 0;

protected:
	std::string _type;
};

#endif

