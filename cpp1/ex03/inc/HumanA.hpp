/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:01:36 by damdam            #+#    #+#             */
/*   Updated: 2024/12/20 03:15:24 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include "Weapon.hpp"
# include <iostream>
# include <string>

class HumanA
{
  private:
	std::string name;
	Weapon &weapon;

  public:
	HumanA(const std::string &name, Weapon &weapon);
	~HumanA();
	void attack() const;
};

#endif