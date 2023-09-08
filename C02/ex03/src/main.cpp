/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:24:49 by vduchi            #+#    #+#             */
/*   Updated: 2023/09/08 16:02:33 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	Fixed const c(Fixed(5.05f) / Fixed(2));
	Fixed const d(Fixed(5.05f) + Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << "B: " << b << std::endl;
	std::cout << "C: " << c << std::endl;
	std::cout << "D: " << d << std::endl;

	std::cout << "Max D B: " << Fixed::max(d, b) << std::endl;
	std::cout << "Max D C: " << Fixed::max(d, c) << std::endl;
	std::cout << "Max B C: " << Fixed::max(b, c) << std::endl;
	std::cout << "Min D B: " << Fixed::min(d, b) << std::endl;
	std::cout << "Min D C: " << Fixed::min(d, c) << std::endl;
	std::cout << "Min B C: " << Fixed::min(b, c) << std::endl;

	return 0;
}
