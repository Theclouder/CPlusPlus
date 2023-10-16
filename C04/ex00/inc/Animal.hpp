/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:42:14 by vduchi            #+#    #+#             */
/*   Updated: 2023/10/16 18:31:44 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H__
#define ANIMAL_H__

#include <iostream>

class Animal
{

public:
	Animal(void);
	Animal(std::string);
	Animal(const Animal &);
	~Animal(void);
	Animal &operator=(const Animal &);

	void setType(std::string);
	std::string getType() const;
	virtual void makeSound() const;

protected:
	std::string _type;
};

#endif

