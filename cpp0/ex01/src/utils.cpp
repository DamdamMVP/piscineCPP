/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 02:25:49 by dalebran          #+#    #+#             */
/*   Updated: 2024/12/19 03:38:23 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>

int strToInt(std::string str)
{
	int result;

	std::stringstream (str) >> result;
	return result;
}