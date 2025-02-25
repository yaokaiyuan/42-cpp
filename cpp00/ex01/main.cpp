/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:27:42 by ykai-yua          #+#    #+#             */
/*   Updated: 2025/02/25 14:27:46 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "main.hpp"

void runPhoneBook() {
    PhoneBook phoneBook;
    std::string command;

    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (command == "ADD") {
            phoneBook.addContact();
        } else if (command == "SEARCH") {
            phoneBook.searchContacts();
        } else if (command == "EXIT") {
            std::cout << "Exiting program." << std::endl;
            break;
        } else {
            std::cout << "Invalid command." << std::endl;
        }
    }
}

int main() {
    runPhoneBook();
    return 0;
}