/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damdam <damdam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:01:36 by damdam            #+#    #+#             */
/*   Updated: 2024/12/19 22:14:31 by damdam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanA
{
private:
    std::string name;
    Weapon &weapon; // Référence vers une arme

public:
    HumanA(const std::string &name, Weapon &weapon);
    void attack() const;
};

#endif