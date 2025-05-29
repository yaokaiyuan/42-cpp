/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:08:41 by ykai-yua          #+#    #+#             */
/*   Updated: 2025/05/29 17:54:12 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    try {
        // Test creating forms with valid grades
        Form form1("Club Registration Form", 50, 30);
        Form form2("Membership Application", 20, 10);
        
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
        Bureaucrat highRank("Mr. President of student council", 1);
		Bureaucrat midRank("Super Oat", 35);
		Bureaucrat lowRank("Oat", 150);
        
        // Test signing forms
        std::cout << "\nTesting form signing:" << std::endl;
        std::cout << "Form1: " << form1 << std::endl;
        std::cout << "Form2: " << form2 << std::endl;
        
        highRank.signForm(form1);
        highRank.signForm(form2);
        
		midRank.signForm(form1);
		midRank.signForm(form2);
        
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
