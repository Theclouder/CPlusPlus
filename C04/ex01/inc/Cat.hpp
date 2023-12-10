/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:42:14 by vduchi            #+#    #+#             */
/*   Updated: 2023/10/16 18:34:41 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H__
#define CAT_H__

#include <iostream>
#include "Brain.hpp"
#include "Animal.hpp"

class Cat : public Animal
{

public:
	Cat(void);
	Cat(const Cat &);
	~Cat(void);
	Cat &operator=(const Cat &);

	void makeSound() const;
	void setIdeas(std::string);
	void setIdeas(std::string, int);
	std::string *getIdeas() const;
	std::string &getIdeas(int) const;

private:
	Brain *brain;
};

#endif
