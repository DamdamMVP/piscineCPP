/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 05:36:30 by dalebran          #+#    #+#             */
/*   Updated: 2024/12/19 06:35:23 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.h"

void randomChump( std::string name )
{
	Zombie zombie = Zombie();
	zombie.setName(name);
	zombie.announce();
}