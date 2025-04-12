/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:44:44 by ykai-yua          #+#    #+#             */
/*   Updated: 2025/04/12 16:44:46 by ykai-yua         ###   ########.fr       */
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

    // Overridden attack function
    void attack(const std::string& target);

    // New member function
    void guardGate();
};

#endif // SCAVTRAP_HPP
