/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:15:30 by vduchi            #+#    #+#             */
/*   Updated: 2023/08/31 10:59:08 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);
		int		getIndex();
		int		getStored();
		void	addNewContact(Contact &newContact);
		Contact	*getContact(int index);

	private:
		int	_index;
		int	_stored;
		Contact	_contactArray[8];
};
