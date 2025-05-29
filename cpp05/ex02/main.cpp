/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 20:50:44 by ykai-yua          #+#    #+#             */
/*   Updated: 2025/05/29 20:50:46 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        // Create bureaucrats with different grades
        Bureaucrat high("TopG", 1);
        Bureaucrat medium("Top Goy", 50);
        Bureaucrat low("Andrew Theft", 150);

        std::cout << "\n=== Testing ShrubberyCreationForm ===" << std::endl;
        ShrubberyCreationForm shrubbery("home");
        std::cout << shrubbery << std::endl;

        // Try to execute without signing
        std::cout << "\nTrying to execute without signing:" << std::endl;
        high.executeForm(shrubbery);

        // Sign and execute with high grade
        std::cout << "\nSigning and executing with high grade:" << std::endl;
        high.signForm(shrubbery);
        high.executeForm(shrubbery);

        // Try to execute with low grade
        std::cout << "\nTrying to execute with low grade:" << std::endl;
		low.signForm(shrubbery);
        low.executeForm(shrubbery);

        std::cout << "\n=== Testing RobotomyRequestForm ===" << std::endl;
        RobotomyRequestForm robotomy("Thrasher and Blastus");
        std::cout << robotomy << std::endl;

		// Try to execute without signing
        std::cout << "\nTrying to execute without signing:" << std::endl;
        high.executeForm(robotomy);
		
		// Sign and execute with high grade
        std::cout << "\nSigning and executing with high grade:" << std::endl;
        high.signForm(robotomy);
        high.executeForm(robotomy);

        // Sign and execute with medium grade
        std::cout << "\nSigning and executing with medium grade:" << std::endl;
        medium.signForm(robotomy);
        medium.executeForm(robotomy);

        std::cout << "\n=== Testing PresidentialPardonForm ===" << std::endl;
        PresidentialPardonForm pardon("Authur Dent");
        std::cout << pardon << std::endl;

		// Try to execute without signing
        std::cout << "\nTrying to execute without signing:" << std::endl;
        high.executeForm(pardon);

		// Sign and execute with high grade
        std::cout << "\nSigning and executing with high grade:" << std::endl;
        high.signForm(pardon);
        high.executeForm(pardon);

        // Try to execute with medium grade (should fail)
        std::cout << "\nTrying to execute with medium grade:" << std::endl;
        medium.signForm(pardon);
        medium.executeForm(pardon);
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
