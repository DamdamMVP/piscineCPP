/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:52:23 by dalebran          #+#    #+#             */
/*   Updated: 2024/12/19 01:48:54 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int isValidCommand(std::string command)
{
	if (command.compare("ADD") != 0 && command.compare("SEARCH") != 0 && command.compare("EXIT") != 0)
		return (0);
	return (1);
}

void getMyCommands()
{
	static PhoneBook myphonebook;
	std::string command;

	do
	{
		std::cout << "Enter a command : ";
		std::getline(std::cin, command);
		if (!isValidCommand(command))
			std::cout << "Invalid command. Available commands : ADD, SEARCH, EXIT." << std::endl;
	} while (!isValidCommand(command));

	if (command.compare("ADD") == 0)
	{
		myphonebook.addContact();
		getMyCommands();
	}
	else if (command.compare("SEARCH") == 0)
	{
		myphonebook.searchContact();
		getMyCommands();
	}
	else if(command.compare("EXIT") == 0)
	{
		std::cout << "Exit" << std::endl;
		return ;
	}
}

int main()
{
	getMyCommands();
	return (0);
}
