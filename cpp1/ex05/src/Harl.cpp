/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 04:03:11 by dalebran          #+#    #+#             */
/*   Updated: 2024/12/20 04:54:57 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

void Harl::debug(void)
{
	std::cout << "It's ok, we got some bugs be it's fine we can play !" << std::endl;
}
void Harl::info(void)
{
	std::cout << "Someone got already 1MM kamas, hope we will got a new serv soon ^^" << std::endl;
}
void Harl::warning(void)
{
	std::cout << "Wtf Ankama, once again my event is bug and I didn't get my rewards !" << std::endl;
}
void Harl::error(void)
{
	std::cout << "8years to make this?! Go back to Wakfu, the best game by far and close this cheat. Wakfu > Dofus" << std::endl;
}

void Harl::complain(std::string level)
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*methods[])(void) = {&Harl::debug, &Harl::info, &Harl::warning,
		&Harl::error};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*methods[i])();
			return ;
		}
	}

	std::cerr << "Unknown level: " << level << std::endl;
}