/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:52:25 by dalebran          #+#    #+#             */
/*   Updated: 2024/12/19 04:29:08 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "utils.hpp"
#include <iomanip>
#include <sstream>

PhoneBook::PhoneBook() : index(0), contactCount(0)
{
	// std::cout << "Mon phonebook est cree !" << std::endl;
}

void PhoneBook::addContact()
{
	if (contactCount < 8)
	{
		contactCount++;
	}
	std::cout << "Add new contact..." << std::endl;
	contacts[index].setContact();
	index = (index + 1) % 8;
}

void PhoneBook::drawContacts() const
{
	std::cout << std::endl << "|"
			  << std::setw(10) << "Index " << "|"
			  << std::setw(10) << "First Name" << "|"
			  << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nickname" << "|" << std::endl;

	
	std::cout << std::setfill('-') << "|"
			  << std::setw(10) << "-" << "|"
			  << std::setw(10) << "-"<< "|"
			  << std::setw(10) << "-" << "|"
			  << std::setw(10) << "-" << "|" << std::setfill(' ') << std::endl;

	for (int i = 0; i < contactCount; ++i)
	{
		contacts[i].displaySummary(i);
	}
}

void PhoneBook::drawFullInfo() const
{
	std::string input;
	int userIndex;
	do{
		std::cout << "Enter a index to see the full values : ";
		std::getline(std::cin, input);
		userIndex = strToInt(input);
		if (userIndex > contactCount || userIndex <= 0)
		{
			std::cout << "Index incorrect. Try again" << std::endl;
		}
	}while(userIndex > contactCount || userIndex <= 0);

	contacts[userIndex-1].displayFullInfo();
}

void PhoneBook::searchContact() const
{
	if (contactCount == 0)
	{
		std::cout << "No contact on PhoneBook !" << std::endl;
		return;
	}

	drawContacts();
	drawFullInfo();
}
