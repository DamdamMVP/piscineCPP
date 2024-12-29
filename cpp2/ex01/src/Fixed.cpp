/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:43:08 by dalebran          #+#    #+#             */
/*   Updated: 2024/12/29 19:32:20 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_value = other.getRawBits();
}

Fixed::Fixed(const int &other)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = other << _fractionalBits;
}

Fixed::Fixed(const float &other)
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(roundf(other * (1 << _fractionalBits)));
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &other)
	{
		this->_value = other.getRawBits();
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

float Fixed::toFloat(void) const
{
	return ((float)this->_value / (1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
	return (this->_value >> _fractionalBits);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}