/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:15:14 by ykai-yua          #+#    #+#             */
/*   Updated: 2025/04/10 17:27:51 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main() {
    Harl harl;

    std::cout << "=== DEBUG ===" << std::endl;
    harl.complain("DEBUG");

    std::cout << "=== INFO ===" << std::endl;
    harl.complain("INFO");

    std::cout << "=== WARNING ===" << std::endl;
    harl.complain("WARNING");

    std::cout << "=== ERROR ===" << std::endl;
    harl.complain("ERROR");

    std::cout << "=== UNKNOWN LEVEL ===" << std::endl;
    harl.complain("WHATEVER");

    return 0;
}
