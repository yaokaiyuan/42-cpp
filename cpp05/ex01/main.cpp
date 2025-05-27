/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:08:41 by ykai-yua          #+#    #+#             */
/*   Updated: 2025/05/27 22:43:15 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    try {
        // Test creating forms with valid grades
        Form form1("Tax Form", 50, 30);
        Form form2("Passport Application", 20, 10);
        
        // Test creating forms with invalid grades
        try {
            Form invalidForm("Invalid Form", 0, 30);
        } catch (const Form::GradeTooHighException& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }
        
        try {
            Form invalidForm("Invalid Form", 151, 30);
        } catch (const Form::GradeTooLowException& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }
        
        // Create bureaucrats
        Bureaucrat highRank("High Rank", 1);
        Bureaucrat lowRank("Low Rank", 150);
        
        // Test signing forms
        std::cout << "\nTesting form signing:" << std::endl;
        std::cout << "Form1: " << form1 << std::endl;
        std::cout << "Form2: " << form2 << std::endl;
        
        // High rank bureaucrat should be able to sign both forms
        highRank.signForm(form1);
        highRank.signForm(form2);
        
        // Low rank bureaucrat should fail to sign form2
        lowRank.signForm(form1);
        lowRank.signForm(form2);
        
        // Print final form states
        std::cout << "\nFinal form states:" << std::endl;
        std::cout << "Form1: " << form1 << std::endl;
        std::cout << "Form2: " << form2 << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }
    
    return 0;
}
