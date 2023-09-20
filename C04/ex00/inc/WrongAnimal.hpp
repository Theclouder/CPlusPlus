/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:42:14 by vduchi            #+#    #+#             */
/*   Updated: 2023/09/15 19:34:50 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_H__
#define WRONGANIMAL_H__

#include <iostream>

class WrongAnimal
{

public:
	WrongAnimal(void);
	WrongAnimal(std::string type);
	WrongAnimal(const WrongAnimal &cpy);
	~WrongAnimal(void);
	WrongAnimal &operator=(const WrongAnimal &cpy);

	void setType(std::string type);
	std::string getType() const;
	void makeSound() const;

protected:
	std::string _type;
};

#endif

