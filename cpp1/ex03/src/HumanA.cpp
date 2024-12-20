/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:01:43 by damdam            #+#    #+#             */
/*   Updated: 2024/12/20 03:17:06 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &weapon) : name(name),
	weapon(weapon)
{
	std::cout << name << " as been create !" << std::endl;
}

HumanA::~HumanA()
{
	std::cout << name << " as been delete !" << std::endl;
}

void HumanA::attack() const
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}