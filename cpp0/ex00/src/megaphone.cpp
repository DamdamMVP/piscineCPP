/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:10:56 by dalebran          #+#    #+#             */
/*   Updated: 2024/12/18 14:32:26 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype> // Pour la fonction std::toupper
#include <iostream>

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < ac; i++)
	{
		for (int j = 0; av[i][j]; j++)
		{
			std::cout << static_cast<char>(std::toupper(av[i][j]));
			// version C :
			// std::cout << (char)(std::toupper(av[i][j]));
		}
	}
	std::cout << std::endl;
	return (0);
}
