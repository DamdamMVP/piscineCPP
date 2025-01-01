/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 12:29:09 by dalebran          #+#    #+#             */
/*   Updated: 2025/01/01 14:39:03 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

static Fixed area(Point const a, Point const b, Point const c) {
  return Fixed(
      0.5f *
      std::abs(
          (a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat())) +
          (b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat())) +
          (c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat()))));
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
  Fixed totalArea = area(a, b, c);
  Fixed area1 = area(point, a, b);
  Fixed area2 = area(point, b, c);
  Fixed area3 = area(point, a, c);
  return (totalArea == (area1 + area2 + area3));
}
