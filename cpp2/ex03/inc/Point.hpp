/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 12:29:26 by dalebran          #+#    #+#             */
/*   Updated: 2025/01/01 15:48:47 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Fixed.hpp"

class Point {
private:
  Fixed const _x;
  Fixed const _y;

public:
  Point();
  Point(const Point &other);
  Point(int x, int y);
  Point(float x, float y);
  Fixed getX() const;
  Fixed getY() const;
  ~Point();
};

bool bsp(Point const a, Point const b, Point const c, Point const point);