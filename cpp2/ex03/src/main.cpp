/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:36:41 by dalebran          #+#    #+#             */
/*   Updated: 2025/01/01 16:08:31 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main() {
  Point a(0.0f, 0.0f);
  Point b(10, 0);
  Point c(0, 10);

  Point p1(0.0f, 2.0f);
  Point p2(15, 5);

  std::cout << "p1 est dans le triangle ? "
            << (bsp(a, b, c, p1) ? "Oui" : "Non") << std::endl;
  std::cout << "p2 est dans le triangle ? "
            << (bsp(a, b, c, p2) ? "Oui" : "Non") << std::endl;

  return 0;
}
