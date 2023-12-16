/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:41:50 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/16 21:43:57 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{

	protected:
		std::string _type;

	public:
		AMateria();
		AMateria(std::string const &);
		AMateria(AMateria const &);
		AMateria& operator=(AMateria const &);
		~AMateria();
		std::string const & getType() const;
		virtual void use(ICharacter&);
		virtual AMateria* clone() const = 0;
};

#endif

