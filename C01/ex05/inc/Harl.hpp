/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:35:53 by vduchi            #+#    #+#             */
/*   Updated: 2023/09/05 09:21:26 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H__
#define HARL_H__
#include <iostream>

class Harl
{
public:
	Harl(void);
	~Harl(void);
	void complain(std::string level);

private:
	std::string _arr[4];
	void (Harl::*_funcPtr[4])(void);
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
};

#endif
