/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 00:35:56 by ykai-yua          #+#    #+#             */
/*   Updated: 2025/06/11 00:35:57 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>

// Forward declarations of the functions
Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main() {
    // Test with pointer
    std::cout << "Testing with pointer:" << std::endl;
    Base* ptr = generate();
    identify(ptr);
    delete ptr;

    // Test with reference
    std::cout << "Testing with reference:" << std::endl;
    Base* ptr2 = generate();
    identify(*ptr2);
    delete ptr2;

    return 0;
}
