/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 15:53:29 by ykai-yua          #+#    #+#             */
/*   Updated: 2025/04/12 16:13:09 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    ClapTrap claptrap("lirili larila");

    claptrap.attack("prr prr patapim");
    claptrap.takeDamage(3);
    claptrap.beRepaired(5);
	claptrap.attack("prr prr patapim");
    claptrap.takeDamage(3);
    claptrap.beRepaired(5);
	claptrap.attack("prr prr patapim");
    claptrap.takeDamage(3);
    claptrap.beRepaired(5);
	claptrap.attack("prr prr patapim");
    claptrap.takeDamage(3);
    claptrap.beRepaired(5);
    claptrap.attack("capucapucino assasino");
    claptrap.takeDamage(10);
    claptrap.beRepaired(2);
	claptrap.attack("tripi tropa");
	claptrap.takeDamage(1);
	claptrap.beRepaired(1);

    return 0;
}
