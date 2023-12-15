/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:15:46 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/15 19:41:47 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{

	public:
		MateriaSource();
		MateriaSource(MateriaSource const &);
		MateriaSource& operator=(MateriaSource const &);
		~MateriaSource();
};

#endif

