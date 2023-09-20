/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 09:54:24 by vduchi            #+#    #+#             */
/*   Updated: 2023/09/20 10:22:25 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <sstream>
#include "PhoneBook.hpp"

std::string cutStr(std::string str, int width)
{
	if ((int)str.length() > width)
		return str.substr(0, width - 1) + ".";
	return str;
}

void	searchContact(PhoneBook &phoneBook)
{
	int	index;
	std::string	line;
	Contact	*toShow;

	if (phoneBook.getStored() == 0)
	{
		std::cout << "No contacts created! Please create a new contact" << std::endl << std::endl;
		return;
	}
	std::cout << std::endl << std::setw(10) << "Index" << "|" << std::setw(10) << "First Name" 
		<< "|" << std::setw(10) << "Last Name" << "|" << std::setw(10) << "Nick Name" << std::endl;
	for (int i = 0; i < phoneBook.getStored(); i++)
	{
		toShow = phoneBook.getContact(i);
		std::cout << std::setw(10) << toShow->getIndex() << "|" << std::setw(10)
			<< cutStr(toShow->getFirstName(), 10) << "|" << std::setw(10) << cutStr(toShow->getLastName(), 10)
			<< "|" << std::setw(10) << cutStr(toShow->getNickName(), 10) << std::endl;
	}
	std::cout << "Enter a contact index: ";
	std::getline(std::cin, line);
	if (line.length() > 1)
	{
		std::cout << "Index not valid!" << std::endl << std::endl;
		return;
	}
	std::istringstream(line) >> index;
	if (index > phoneBook.getStored())
	{
		std::cout << "Contact with this index doesn't exist!" << std::endl << std::endl;
		return;
	}
	toShow = phoneBook.getContact(index - 1);
	std::cout << std::setw(20) << "First Name"
						<< "|" << std::setw(20) << "Last Name"
						<< "|" << std::setw(20) << "Nick Name"
						<< "|" << std::setw(20) << "Phone Num"
						<< "| "
						<< "Darkest Secret" << std::endl;
	std::cout << std::setw(20) << cutStr(toShow->getFirstName(), 20) << "|" << std::setw(20)
		<< cutStr(toShow->getLastName(), 20) << "|" << std::setw(20) << cutStr(toShow->getNickName(), 20)
		<< "|" << std::setw(20) << cutStr(toShow->getPhoneNumber(), 20) << "| " << toShow->getDarkestSecret()
		<< std::endl << std::endl;

}

int takeValue(std::string &ref, std::string value)
{
	std::cout << std::endl
						<< "Enter the " << value << ": ";
	std::getline(std::cin, ref);
	if (std::cin.eof() == 1)
		return 1;
	return 0;
}

int addContact(PhoneBook &phoneBook)
{
	std::string	first;
	std::string	last;
	std::string	nick;
	std::string	phone;
	std::string	secret;
	Contact	newContact(phoneBook.getIndex() + 1);

	if (takeValue(first, "first name") || takeValue(last, "last name") || takeValue(nick, "nickname") || takeValue(phone, "phone number") || takeValue(secret, "darkest secret"))
		return 1;
	newContact.setFirstName(first);
	newContact.setLastName(last);
	newContact.setNickName(nick);
	newContact.setPhoneNumber(phone);
	newContact.setDarkestSecret(secret);
	phoneBook.addNewContact(newContact);
	std::cout << "Contact added successfully!" << std::endl << std::endl;
	return 0;
}

int	main(void)
{
	std::string	line;
	PhoneBook	phoneBook;

	while (42)
	{
		std::cout << "Enter a command: ";
		std::getline(std::cin, line);
		if (std::cin.eof() == 1)
			return 0;
		if (line.compare("ADD") && line.compare("SEARCH") && line.compare("EXIT"))
		{
			std::cout << std::endl << "Command: " << line << " not allowed!" << std::endl;
			std::cout << "Commands allowed are: ADD, SEARCH or EXIT!" << std::endl << std::endl;
			continue;
		}
		if (!line.compare("ADD"))
		{
			if (addContact(phoneBook))
				return 1;
		}
		else if (!line.compare("SEARCH"))
			searchContact(phoneBook);
		else
		{
			std::cout << "Bye!" << std::endl;
			return 0;
		}
		std::cin.clear();
	}
}
