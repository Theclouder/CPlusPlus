/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:42:14 by vduchi            #+#    #+#             */
/*   Updated: 2023/09/15 19:44:32 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H__
#define CAT_H__

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{

public:
	Cat(void);
	Cat(const Cat &cpy);
	~Cat(void);
	Cat &operator=(const Cat &cpy);

	void makeSound() const;
};

#endif

