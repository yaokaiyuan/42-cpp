/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:37:28 by ykai-yua          #+#    #+#             */
/*   Updated: 2025/04/19 21:10:31 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << name << " created with " << hitPoints << " hit points, "
              << energyPoints << " energy points, and " << attackDamage << " attack damage." << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << name << " destroyed." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "FragTrap " << name << " copied." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    std::cout << "FragTrap " << name << " assigned." << std::endl;
    return *this;
}

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << name << " requests a positive high five!" << std::endl;
}
