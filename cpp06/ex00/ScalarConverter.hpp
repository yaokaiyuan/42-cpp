/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 21:39:50 by ykai-yua          #+#    #+#             */
/*   Updated: 2025/06/10 21:40:13 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include <limits>
# include <cstdlib>
# include <cmath>

class ScalarConverter {
private:
    // Make the class non-instantiable
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();

    // Helper methods
    static bool isChar(const std::string& literal);
    static bool isInt(const std::string& literal);
    static bool isFloat(const std::string& literal);
    static bool isDouble(const std::string& literal);
    static bool isPseudoLiteral(const std::string& literal);

    static void convertFromChar(char c);
    static void convertFromInt(int i);
    static void convertFromFloat(float f);
    static void convertFromDouble(double d);
    static void convertFromPseudoLiteral(const std::string& literal);

public:
    static void convert(const std::string& literal);
};

#endif
