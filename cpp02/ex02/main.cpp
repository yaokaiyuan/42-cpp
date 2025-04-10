/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 20:46:18 by ykai-yua          #+#    #+#             */
/*   Updated: 2025/04/10 22:04:47 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main(void) {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;      // 0
    std::cout << ++a << std::endl;    // 0.00390625
    std::cout << a << std::endl;      // 0.00390625
    std::cout << a++ << std::endl;    // 0.00390625
    std::cout << a << std::endl;      // 0.0078125
    std::cout << b << std::endl;      // 10.1016
    std::cout << Fixed::max(a, b) << std::endl;  // 10.1016
	std::cout << Fixed::min(a, b) << std::endl;  // 0.0078125

	std::cout << (a < b) << std::endl;   // 1 (true)
    std::cout << (a > b) << std::endl;   // 0 (false)
    std::cout << (a <= b) << std::endl;  // 1 (true)
    std::cout << (a >= b) << std::endl;  // 0 (false)
    std::cout << (a == b) << std::endl;  // 0 (false)
    std::cout << (a != b) << std::endl;  // 1 (true)
	
	std::cout << "a + b: " << (a + b) << std::endl;
    std::cout << "b - a: " << (b - a) << std::endl;
    std::cout << "a * b: " << (a * b) << std::endl;
    std::cout << "b / Fixed(2): " << (b / Fixed(2)) << std::endl;
	
    return 0;
}
