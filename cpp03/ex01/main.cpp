/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:44:26 by ykai-yua          #+#    #+#             */
/*   Updated: 2025/04/12 16:44:28 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ClapTrap claptrap("tralalero tralala");
    claptrap.attack("fruli frula");
    claptrap.takeDamage(3);
    claptrap.beRepaired(5);

    std::cout << "\n--- Creating ScavTrap ---" << std::endl;
    ScavTrap scavtrap("tung tung tung tung tung sahur");
    scavtrap.attack("chimpanzini bananini");
    scavtrap.takeDamage(20);
    scavtrap.beRepaired(10);
    scavtrap.guardGate();

    std::cout << "\n--- End of test ---" << std::endl;
    return 0;
}
