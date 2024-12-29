/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:43:06 by dalebran          #+#    #+#             */
/*   Updated: 2024/12/29 19:17:09 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cmath>
#include <iostream>

class Fixed
{
  private:
	int _value;
	static const int _fractionalBits = 8;

  public:
	Fixed();
	Fixed(const Fixed &other);
	Fixed(const int &other);
	Fixed(const float &other);
	~Fixed();
	Fixed &operator=(const Fixed &other);
	float toFloat(void) const;
	int toInt(void) const;
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
