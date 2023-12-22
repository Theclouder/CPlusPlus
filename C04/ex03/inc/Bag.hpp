/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bag.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 20:59:43 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/22 22:01:17 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BAG_HPP
# define BAG_HPP

# include <iostream>
# include "AMateriaNode.hpp"

class Bag
{

	private:
		int _size;
		AMateriaNode* _first;
		AMateriaNode* _last;
	
	public:
		Bag();
		Bag(Bag const &);
		Bag& operator=(Bag const &);
		~Bag();

		void clearList();
		void addNode(AMateriaNode const *);
		AMateriaNode* getLast() const;
//		AMateriaNode* getNode(int) const;
};

#endif
