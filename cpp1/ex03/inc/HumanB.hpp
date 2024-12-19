/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damdam <damdam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:01:34 by damdam            #+#    #+#             */
/*   Updated: 2024/12/19 22:14:27 by damdam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanB
{
private:
    std::string name;
    Weapon *weapon; // Pointeur vers une arme (peut être nul)

public:
    HumanB(const std::string &name);
    void setWeapon(Weapon &weapon);
    void attack() const;
};

#endif