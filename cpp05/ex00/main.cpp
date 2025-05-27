/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:08:41 by ykai-yua          #+#    #+#             */
/*   Updated: 2025/05/27 15:08:43 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    try {
        // Test valid bureaucrat creation
        std::cout << "Creating a valid bureaucrat..." << std::endl;
        Bureaucrat bob("Bob", 50);
        std::cout << bob << std::endl;

        // Test grade increment
        std::cout << "\nIncrementing grade..." << std::endl;
        bob.incrementGrade();
        std::cout << bob << std::endl;

        // Test grade decrement
        std::cout << "\nDecrementing grade..." << std::endl;
        bob.decrementGrade();
        std::cout << bob << std::endl;

        // Test too high grade
        std::cout << "\nTrying to create a bureaucrat with grade 0..." << std::endl;
        Bureaucrat invalid1("Invalid1", 0);
    }
    catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        // Test too low grade
        std::cout << "\nTrying to create a bureaucrat with grade 151..." << std::endl;
        Bureaucrat invalid2("Invalid2", 151);
    }
    catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        // Test incrementing highest grade
        std::cout << "\nCreating a bureaucrat with grade 1..." << std::endl;
        Bureaucrat top("Top", 1);
        std::cout << top << std::endl;
        std::cout << "Trying to increment highest grade..." << std::endl;
        top.incrementGrade();
    }
    catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        // Test decrementing lowest grade
        std::cout << "\nCreating a bureaucrat with grade 150..." << std::endl;
        Bureaucrat bottom("Bottom", 150);
        std::cout << bottom << std::endl;
        std::cout << "Trying to decrement lowest grade..." << std::endl;
        bottom.decrementGrade();
    }
    catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
