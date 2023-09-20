/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:42:14 by vduchi            #+#    #+#             */
/*   Updated: 2023/09/15 19:50:30 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_H__
#define WRONGCAT_H__

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{

public:
	WrongCat(void);
	WrongCat(const WrongCat &cpy);
	~WrongCat(void);
	WrongCat &operator=(const WrongCat &cpy);

	void makeSound() const;
};

#endif

