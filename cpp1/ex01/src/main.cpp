/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damdam <damdam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 05:35:54 by dalebran          #+#    #+#             */
/*   Updated: 2024/12/19 17:52:10 by damdam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.h"

int main()
{
	int i;

	Zombie *zombies = zombieHorde(5, "albert");
	for (i = 0; i < 5; i++)
	{
		zombies[i].announce();
	}
	delete[] zombies;
	return 0;
}