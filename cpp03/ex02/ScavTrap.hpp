/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:37:56 by ykai-yua          #+#    #+#             */
/*   Updated: 2025/04/19 21:11:22 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
    // Constructor
    ScavTrap(const std::string& name);
    
    // Destructor
    ~ScavTrap();

	// Copy constructor
    ScavTrap(const ScavTrap& other);

    // Copy assignment operator
    ScavTrap& operator=(const ScavTrap& other);

    // Overridden attack function
    void attack(const std::string& target);

    // New member function
    void guardGate();
};

#endif // SCAVTRAP_HPP