/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 21:37:50 by ykai-yua          #+#    #+#             */
/*   Updated: 2025/04/10 21:37:59 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed area(Point const a, Point const b, Point const c) {
    return Fixed(
        (a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) +
         b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()) +
         c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())) / 2.0f
    ).toFloat() < 0 ? Fixed(-1 * Fixed(
        (a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) +
         b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()) +
         c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())) / 2.0f
    ).toFloat()) : Fixed(
        (a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) +
         b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()) +
         c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())) / 2.0f
    );
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed A = area(a, b, c);
    Fixed A1 = area(point, b, c);
    Fixed A2 = area(a, point, c);
    Fixed A3 = area(a, b, point);

    if (A1 == Fixed(0) || A2 == Fixed(0) || A3 == Fixed(0))
        return false;

    return A == A1 + A2 + A3;
}
