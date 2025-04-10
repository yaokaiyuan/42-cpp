/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:53:46 by ykai-yua          #+#    #+#             */
/*   Updated: 2025/04/08 15:53:48 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <sstream>

PhoneBook::PhoneBook() : contactCount(0) {}

void PhoneBook::addContact() {
    if (contactCount < 8) {
        contacts[contactCount].setContactInfo();
        contactCount++;
    } else {
        std::cout << "PhoneBook is full. Replacing the oldest contact." << std::endl;
        for (int i = 1; i < 8; i++) {
            contacts[i - 1] = contacts[i];
        }
        contacts[7].setContactInfo();
    }
}

void PhoneBook::searchContacts() const {
    std::cout << std::setw(10) << "Index" 
              << "|" << std::setw(10) << "First Name" 
              << "|" << std::setw(10) << "Last Name" 
              << "|" << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < contactCount; i++) {
        std::cout << std::setw(10) << i 
                  << "|" << std::setw(10) << contacts[i].getFirstName().substr(0, 9) + (contacts[i].getFirstName().length() > 9 ? "." : "") 
                  << "|" << std::setw(10) << contacts[i].getLastName().substr(0, 9) + (contacts[i].getLastName().length() > 9 ? "." : "") 
                  << "|" << std::setw(10) << contacts[i].getNickname().substr(0, 9) + (contacts[i].getNickname().length() > 9 ? "." : "") << std::endl;
    }

    if (contactCount == 0) {
        std::cout << "No contacts available." << std::endl;
        return;
    }

    int index;
    std::cout << "Enter index to display contact: ";
    while (true) {
        std::string input;
        std::getline(std::cin, input);
        if (input.empty()) {
        std::cout << "Enter index to display contact: ";
        continue;
        }
        std::istringstream iss(input);
        if (!(iss >> index)) {
            std::cout << "Invalid input. Please enter a number." << std::endl;
            std::cout << "Enter index to display contact: ";
            continue;
        }
        if (index < 0 || index >= contactCount) {
            std::cout << "Invalid index. Please enter a number between 0 and " << contactCount - 1 << "." << std::endl;
            std::cout << "Enter index to display contact: ";
            continue;
        }
        contacts[index].displayContact();
        break;
    }
}
