/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:42:14 by vduchi            #+#    #+#             */
/*   Updated: 2023/10/16 18:21:23 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H__
#define BRAIN_H__

#include <iostream>

class Brain
{

public:
	Brain(void);
	Brain(const Brain &cpy);
	~Brain(void);
	Brain &operator=(const Brain &cpy);

protected:
	std::string ideas[100];
};

#endif
