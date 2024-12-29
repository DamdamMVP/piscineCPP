/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:01:34 by damdam            #+#    #+#             */
/*   Updated: 2024/12/29 14:38:49 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

# include "Weapon.hpp"
# include <iostream>
# include <string>

class HumanB
{
  private:
	std::string name;
	Weapon *weapon;

  public:
	HumanB(const std::string &name);
	~HumanB();
	void setWeapon(Weapon &weapon);
	void attack() const;
};

#endif