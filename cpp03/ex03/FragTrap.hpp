/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:23:19 by ykai-yua          #+#    #+#             */
/*   Updated: 2025/04/19 21:14:12 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
public:
	static const unsigned int DEFAULT_HIT_POINTS = 100;
    static const unsigned int DEFAULT_ENERGY_POINTS = 100;
    static const unsigned int DEFAULT_ATTACK_DAMAGE = 30;
    FragTrap(); 
    FragTrap(const std::string& name);
	FragTrap(const FragTrap& other);
    FragTrap& operator=(const FragTrap& other);
    virtual ~FragTrap();
    void highFivesGuys(void);
};

#endif
