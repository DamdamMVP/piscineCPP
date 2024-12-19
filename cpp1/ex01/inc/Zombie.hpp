/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 05:38:13 by dalebran          #+#    #+#             */
/*   Updated: 2024/12/19 06:29:53 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#pragma once

#include "zombie.h"

class Zombie
{
  private:
	std::string name;

  public:
	Zombie();
	~Zombie();
	void setName(std::string name);
	void announce(void);
};