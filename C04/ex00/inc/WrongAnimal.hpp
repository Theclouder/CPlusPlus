/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:42:14 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/10 13:35:43 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{

public:
	WrongAnimal(void);
	WrongAnimal(std::string);
	WrongAnimal(const WrongAnimal &);
	~WrongAnimal(void);
	WrongAnimal &operator=(const WrongAnimal &);

	void setType(std::string);
	std::string getType() const;
	void makeSound() const;

protected:
	std::string _type;
};

#endif

