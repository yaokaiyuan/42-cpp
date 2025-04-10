/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 21:37:06 by ykai-yua          #+#    #+#             */
/*   Updated: 2025/04/10 21:37:11 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
    Fixed const x;
    Fixed const y;
public:
    Point();
    Point(const float x, const float y);
    Point(const Point&);
    Point& operator=(const Point&);
    ~Point();

    Fixed getX() const;
    Fixed getY() const;
};

#endif
