/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 21:38:24 by ykai-yua          #+#    #+#             */
/*   Updated: 2025/04/10 21:38:31 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main() {
    Point a(0, 0);
    Point b(10, 0);
    Point c(5, 10);

    Point inside(5, 5);
    Point edge(5, 0);
    Point outside(20, 20);

    std::cout << "Inside: " << (bsp(a, b, c, inside) ? "True" : "False") << std::endl;
    std::cout << "Edge: " << (bsp(a, b, c, edge) ? "True" : "False") << std::endl;
    std::cout << "Outside: " << (bsp(a, b, c, outside) ? "True" : "False") << std::endl;

    return 0;
}
