/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:42:20 by vduchi            #+#    #+#             */
/*   Updated: 2024/01/25 10:59:45 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

Serialize::Serialize() {}

Serialize::Serialize(const Serialize & rhs)
{
	*this = rhs;
}

Serialize& Serialize::operator=(const Serialize & rhs) { (void)rhs; return *this; }

Serialize::~Serialize() {}

uintptr_t Serialize::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serialize::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
