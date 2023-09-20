/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:27:43 by vduchi            #+#    #+#             */
/*   Updated: 2023/09/20 12:46:19 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook (void)	{ this->_stored = 0; }// std::cout << "Phone book created" << std::endl; }

PhoneBook::~PhoneBook (void) {} // std::cout << "Phone book destroyed" << std::endl; }

int	PhoneBook::getIndex(void) { return (this->_index % 8); }

int	PhoneBook::getStored(void) { return this->_stored; }

void PhoneBook::addNewContact (Contact &newContact) {
	_contactArray[this->_index % 8].setIndex(newContact.getIndex());
	_contactArray[this->_index % 8].setFirstName(newContact.getFirstName());
	_contactArray[this->_index % 8].setLastName(newContact.getLastName());
	_contactArray[this->_index % 8].setNickName(newContact.getNickName());
	_contactArray[this->_index % 8].setPhoneNumber(newContact.getPhoneNumber());
	_contactArray[this->_index % 8].setDarkestSecret(newContact.getDarkestSecret());
	this->_index++;
	if (this->_stored < 8)
		this->_stored++;
}

Contact *PhoneBook::getContact (int index) {
	return &(this->_contactArray[index]);
}
