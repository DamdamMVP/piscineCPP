/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damdam <damdam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:01:38 by damdam            #+#    #+#             */
/*   Updated: 2024/12/19 21:50:28 by damdam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Weapon
{
private:
	std::string type;

public:
	Weapon(const std::string &type);
	~Weapon();
	const std::string &getType() const;
	void setType(const std::string &newType);
};