/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:42:06 by ykai-yua          #+#    #+#             */
/*   Updated: 2025/04/08 19:48:00 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main() {
    int N = 5;
    std::string name = "HordeZombie";
    
    // Create a horde of zombies
    Zombie* horde = zombieHorde(N, name);
    
    // Make each zombie announce itself
    for (int i = 0; i < N; i++) {
        horde[i].announce();
    }
    
    // Delete the entire horde
    delete[] horde;
    
    return 0;
}