/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:42:14 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/10 14:23:26 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

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
	const std::string *getIdeas() const;
	const std::string &getIdeas(int) const;

private:
	Brain *brain;
};

#endif
