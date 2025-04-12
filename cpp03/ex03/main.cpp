/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:23:25 by ykai-yua          #+#    #+#             */
/*   Updated: 2025/04/12 19:23:30 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main() {
    DiamondTrap diamond("spioniro golubiro");

    diamond.whoAmI();
    diamond.attack("golubineli piconeli");
    diamond.takeDamage(20);
    diamond.beRepaired(10);
	diamond.highFivesGuys();
	diamond.guardGate();
    return 0;
}
