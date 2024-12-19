/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 05:36:07 by dalebran          #+#    #+#             */
/*   Updated: 2024/12/19 06:39:24 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.h"

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
	std::cout << name << " is delete." << std::endl;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}