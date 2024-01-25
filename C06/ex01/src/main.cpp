/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:48:05 by vduchi            #+#    #+#             */
/*   Updated: 2024/01/25 10:59:37 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "Serialize.hpp"

int main()
{
	{
		Data data;
		data.id = 0;
		data.value = 8253;
		data.name = "Valerio";
		uintptr_t p = Serialize::serialize(&data);
		std::cout << CYAN << "Int Pointer p: " << p << RESET << std::endl;
		Data *dataPtr = Serialize::deserialize(p);
		std::cout << CYAN << "Data pointer p: " << dataPtr << RESET << std::endl;
		std::cout << GREEN << "Data pointer values: \tid: " << dataPtr->id << RESET << std::endl;
		std::cout << GREEN << "\t\t\tvalue: " << dataPtr->value << RESET << std::endl;
		std::cout << GREEN << "\t\t\tname: " << dataPtr->name << RESET << std::endl;
	}
}
