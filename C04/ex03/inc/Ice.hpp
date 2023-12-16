/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:12:58 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/16 22:45:34 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"

class Ice : public AMateria
{

	public:
		Ice();
		Ice(Ice const &);
		Ice& operator=(Ice const &);
		~Ice();
		void use(ICharacter&);
		AMateria* clone() const;
};

#endif

