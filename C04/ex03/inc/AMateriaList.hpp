/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateriaList.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:41:50 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/19 16:46:21 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIALIST_HPP
# define AMATERIALIST_HPP

# include <iostream>
# include "AMateria.hpp"

class AMateriaList
{

	private:
		AMateriaList* _bef;
		AMateriaList* _next;
		AMateria* _mat;

	public:
		AMateriaList();
		AMateriaList(AMateria const &);
		AMateriaList& operator=(AMateria const &);
		~AMateriaList();

		void setMat(AMateria*);
		void setBef(AMateriaList*);
		void setNext(AMateriaList*);
		AMateria* getMat() const;
		AMateriaList* getBef() const;
		AMateriaList* getNext() const;
};

#endif

