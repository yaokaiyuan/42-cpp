/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 21:36:56 by ykai-yua          #+#    #+#             */
/*   Updated: 2025/04/10 21:37:35 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float xVal, const float yVal) : x(xVal), y(yVal) {}

Point::Point(const Point& other) : x(other.x), y(other.y) {}

Point& Point::operator=(const Point& other) {
    // const members can't be reassigned
    (void)other;
    return *this;
}

Point::~Point() {}

Fixed Point::getX() const { return x; }
Fixed Point::getY() const { return y; }
