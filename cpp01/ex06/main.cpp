/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:31:54 by ykai-yua          #+#    #+#             */
/*   Updated: 2025/04/10 17:35:22 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int getLevelIndex(const std::string& level) {
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; ++i) {
        if (level == levels[i])
            return i;
    }
    return -1;
}

int main(int argc, char** argv) {
    Harl harl;

    if (argc != 2) {
        std::cerr << "Usage: ./harlFilter <LEVEL>" << std::endl;
        return 1;
    }

    std::string inputLevel = argv[1];
    int levelIndex = getLevelIndex(inputLevel);

    switch (levelIndex) {
        case 0:
            harl.complain("DEBUG");
        case 1:
            harl.complain("INFO");
        case 2:
            harl.complain("WARNING");
        case 3:
            harl.complain("ERROR");
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }

    return 0;
}
