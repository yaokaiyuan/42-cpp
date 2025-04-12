/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:37:44 by ykai-yua          #+#    #+#             */
/*   Updated: 2025/04/12 17:37:46 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

int main() {
    FragTrap frag("boneca ambalabu");

	frag.attack("octopusini blueberrini");
	frag.takeDamage(8);
	frag.beRepaired(2);
    frag.highFivesGuys();
    return 0;
}
