/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 12:29:32 by dalebran          #+#    #+#             */
/*   Updated: 2025/01/01 15:48:49 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}
Point::Point(const Point &other) : _x(other._x), _y(other._y) {}
Point::Point(int x, int y) : _x(x), _y(y) {}
Point::Point(float x, float y) : _x(x), _y(y) {}
Point::~Point() {}

Fixed Point::getX() const { return _x; }
Fixed Point::getY() const { return _y; }
