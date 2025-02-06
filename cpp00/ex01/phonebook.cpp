
#include "phonebook.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

PhoneBook::PhoneBook() : contactCount(0) {}

void PhoneBook::addContact() {
    if (contactCount < 8) {
        contacts[contactCount].setContactInfo();
        contactCount++;
    } else {
        // 替换最旧的联系人
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
        std::cout << "No contacts available." << std::endl; // 如果没有联系人，打印提示信息
        return;
    }

    int index;
    std::cout << "Enter index to display contact: ";

    // 读取输入并检查是否成功
    while (true) {
        if (!(std::cin >> index)) {
            std::cin.clear(); // 清除错误标志
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清空输入缓冲区
            std::cout << "Invalid input. Please enter a number." << std::endl;
            std::cout << "Enter index to display contact: "; // 重新提示用户输入
            continue; // 继续循环，等待有效输入
        }

        // 检查输入的索引是否在有效范围内
        if (index < 0 || index >= contactCount) {
            std::cout << "Invalid index. Please enter a number between 0 and " << contactCount - 1 << "." << std::endl;
            std::cout << "Enter index to display contact: "; // 重新提示用户输入
            std::cin.clear(); // 清除错误标志
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清空输入缓冲区
            continue; // 继续循环，等待有效输入
        }

        std::cin.ignore(); // 清除输入缓冲区中的换行符
        contacts[index].displayContact(); // 显示联系人信息
        break; // 退出循环
    }
}
