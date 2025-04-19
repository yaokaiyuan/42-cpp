/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:23:43 by ykai-yua          #+#    #+#             */
/*   Updated: 2025/04/19 21:15:05 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
public:
	static const unsigned int DEFAULT_HIT_POINTS = 100;
    static const unsigned int DEFAULT_ENERGY_POINTS = 50;
    static const unsigned int DEFAULT_ATTACK_DAMAGE = 20;
    ScavTrap();
    ScavTrap(const std::string& name);
    virtual ~ScavTrap();
    ScavTrap(const ScavTrap& other);
    ScavTrap& operator=(const ScavTrap& other);
    void attack(const std::string& target);
    void guardGate();
};

#endif