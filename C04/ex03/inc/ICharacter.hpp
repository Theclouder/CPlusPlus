/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:15:23 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/16 22:44:40 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>
# include "AMateria.hpp"

class AMateria;

class ICharacter
{

	public:
		virtual ~ICharacter() {}
		virtual void unequip(int) = 0;
		virtual void equip(AMateria*) = 0;
		virtual void use(int, ICharacter&) = 0;
		virtual std::string const & getName() const = 0;
};

#endif

