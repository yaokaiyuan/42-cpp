/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:22:57 by ykai-yua          #+#    #+#             */
/*   Updated: 2025/04/19 21:12:55 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap(), name(name) {
    hitPoints = FragTrap::DEFAULT_HIT_POINTS;
    energyPoints = ScavTrap::DEFAULT_ENERGY_POINTS;
    attackDamage = FragTrap::DEFAULT_ATTACK_DAMAGE;
    std::cout << "DiamondTrap " << name << " created with " << hitPoints << " hit points, "
              << energyPoints << " energy points, and " << attackDamage << " attack damage." << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << name << " destroyed." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), FragTrap(other), ScavTrap(other), name(other.name) {
    std::cout << "DiamondTrap " << name << " copied." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        FragTrap::operator=(other);
        ScavTrap::operator=(other);
        name = other.name;
    }
    std::cout << "DiamondTrap " << name << " assigned." << std::endl;
    return *this;
}

void DiamondTrap::whoAmI() {
    std::cout << "I am " << name << " and my ClapTrap name is " << ClapTrap::name << "." << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}
