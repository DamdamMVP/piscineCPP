/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:01:41 by damdam            #+#    #+#             */
/*   Updated: 2024/12/20 03:16:49 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) : name(name), weapon(NULL)
{
	std::cout << name << " as been create !" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << name << " as been delete !" << std::endl;

}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void HumanB::attack() const
{
	if (weapon)
	{
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	}
	else
	{
		std::cout << name << " has no weapon to attack with!" << std::endl;
	}
}