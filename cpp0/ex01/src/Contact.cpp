/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:52:28 by dalebran          #+#    #+#             */
/*   Updated: 2024/12/19 03:54:50 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iomanip>

std::string Contact::getFirstName() const
{
	return firstName;
}

std::string Contact::getLastName() const
{
	return lastName;
}

std::string Contact::getNickname() const
{
	return nickname;
}

std::string Contact::truncateValue(std::string value) const
{
	if (value.length() > 10)
	{
		return (value.substr(0, 9) + ".");
	}
	return value;
}

void Contact::setContact()
{
	setFirstName();
	setLastName();
	setNickname();
	setPhoneNumber();
	setDarkestSecret();
	std::cout << std::endl;
}

void Contact::setFirstName()
{
	do
	{
		std::cout << "Enter your first name : ";
		std::getline(std::cin, firstName);
		if (firstName.empty())
			std::cout << "First name is empty ! Try again" << std::endl;
	} while (firstName.empty());
}

void Contact::setLastName()
{
	do
	{
		std::cout << "Enter your last name : ";
		std::getline(std::cin, lastName);
		if (lastName.empty())
			std::cout << "Last name is empty ! Try again" << std::endl;
	} while (lastName.empty());
}

void Contact::setNickname()
{
	do
	{
		std::cout << "Enter your nickname : ";
		std::getline(std::cin, nickname);
		if (nickname.empty())
			std::cout << "The nickname is empty ! Try again" << std::endl;
	} while (nickname.empty());
}

void Contact::setPhoneNumber()
{
	do
	{
		std::cout << "Enter your phone number : ";
		std::getline(std::cin, phoneNumber);
		if (phoneNumber.empty())
			std::cout << "The phone number is empty ! Try again" << std::endl;
	} while (phoneNumber.empty());
}

void Contact::setDarkestSecret()
{
	do
	{
		std::cout << "Enter your secret : ";
		std::getline(std::cin, darkestSecret);
		if (darkestSecret.empty())
			std::cout << "The secret is empty ! Try again" << std::endl;
	} while (darkestSecret.empty());
}

void Contact::displaySummary(int i) const
{
	std::cout << "|"
			  << std::setw(9) << i + 1 << " |"
			  << std::setw(10) << truncateValue(getFirstName()) << "|"
			  << std::setw(10) << truncateValue(getLastName()) << "|"
			  << std::setw(10) << truncateValue(getNickname()) << "|" << std::endl;
}

void Contact::displayFullInfo() const
{
	std::cout << "First name   : " << firstName << std::endl;
	std::cout << "Last name    : " << lastName << std::endl;
	std::cout << "Nickname     : " << nickname << std::endl;
	std::cout << "Phone number : " << phoneNumber << std::endl;
	std::cout << "Secret       : " << darkestSecret << std::endl;
}