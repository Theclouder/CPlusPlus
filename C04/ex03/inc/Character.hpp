/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:55:00 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/16 22:56:38 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"

class Character : public ICharacter
{

	private:
		std::string _name;
		AMateria* slots[4];

	public:
		Character();
		Character(Character const &);
		Character(std::string const &);
		Character& operator=(Character const &);
		~Character();
		void unequip(int);
		void equip(AMateria*);
		void use(int, ICharacter&);
		std::string const & getName() const;
};

#endif

