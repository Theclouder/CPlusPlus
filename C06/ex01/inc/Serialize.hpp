/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:36:34 by vduchi            #+#    #+#             */
/*   Updated: 2024/01/25 10:41:52 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZE_HPP
# define SERIALIZE_HPP

#include <iostream>
#include "Data.hpp"

class Serialize
{
	private:
		Serialize();
		Serialize(const Serialize &);
		Serialize& operator=(const Serialize &);
		~Serialize();

	public:
		static uintptr_t serialize(Data*);
		static Data* deserialize(uintptr_t);
};

#endif

