/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damdam <damdam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 05:38:13 by dalebran          #+#    #+#             */
/*   Updated: 2024/12/19 17:34:11 by damdam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHPP
#define ZOMBIEHPP

#include "zombie.h"
#include <iostream>

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

#endif