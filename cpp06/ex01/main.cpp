/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 23:47:38 by ykai-yua          #+#    #+#             */
/*   Updated: 2025/07/28 19:34:08 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
    // Create a Data object
    Data data;
    data.name = "Oat";
    data.gooning_times_per_day = 13;
    data.max_edging_hours = 1.5;

    // Print original data
    std::cout << "Original Data:" << std::endl;
    std::cout << "Name: " << data.name << std::endl;
    std::cout << "Gooning times per day: " << data.gooning_times_per_day << std::endl;
    std::cout << "Max edging hours: " << data.max_edging_hours << std::endl;
    std::cout << "Address: " << &data << std::endl;
    std::cout << std::endl;

    // Serialize the pointer
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized value: " << raw << std::endl;
    std::cout << std::endl;

    // Deserialize back to a pointer
    Data* ptr = Serializer::deserialize(raw);
    std::cout << "Deserialized Data:" << std::endl;
    std::cout << "Name: " << ptr->name << std::endl;
    std::cout << "Gooning times per day: " << ptr->gooning_times_per_day << std::endl;
    std::cout << "Max edging hours: " << ptr->max_edging_hours << std::endl;
    std::cout << "Address: " << ptr << std::endl;
    std::cout << std::endl;

    // Verify the pointers are equal
    std::cout << "Pointer comparison: " << (&data == ptr ? "Equal" : "Not equal") << std::endl;

    return 0;
}
