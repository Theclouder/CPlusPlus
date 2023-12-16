/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:57:12 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/16 22:45:41 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"

class Cure : public AMateria
{

	public:
		Cure();
		Cure(Cure const &);
		Cure& operator=(Cure const &);
		~Cure();
		void use(ICharacter&);
		AMateria* clone() const;
};

#endif

