/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 05:35:54 by dalebran          #+#    #+#             */
/*   Updated: 2024/12/19 06:35:49 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.h"

int	main()
{
	Zombie *roger = newZombie("roger");
	roger->announce();
	randomChump("gilbert");
	delete roger;
	return 0;
}