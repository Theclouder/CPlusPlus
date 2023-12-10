/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:42:14 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/10 14:23:04 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{

public:
	Brain(void);
	Brain(const Brain &);
	~Brain(void);
	Brain &operator=(const Brain &);
	void setIdeas(std::string);
	void setIdeas(std::string, int);
	const std::string *getIdeas() const;
	const std::string &getIdeas(int) const;

protected:
	std::string ideas[100];
};

#endif
