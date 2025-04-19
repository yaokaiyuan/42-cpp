/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:22:51 by ykai-yua          #+#    #+#             */
/*   Updated: 2025/04/19 21:07:56 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {
protected:
    std::string name;
    unsigned int hitPoints;
    unsigned int energyPoints;
    unsigned int attackDamage;

public:
    // Constructor
    ClapTrap(const std::string& name);
	ClapTrap();
    
    // Virtual Destructor
    virtual ~ClapTrap();

	// Copy constructor
    ClapTrap(const ClapTrap& other);

    // Copy assignment operator
    ClapTrap& operator=(const ClapTrap& other);
	
    // Virtual Member functions
    virtual void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif // CLAPTRAP_HPP