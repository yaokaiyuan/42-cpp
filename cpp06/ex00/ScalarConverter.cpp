/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 21:39:29 by ykai-yua          #+#    #+#             */
/*   Updated: 2025/06/10 22:16:39 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isChar(const std::string& literal) {
    if (literal.length() == 1 && isprint(literal[0])) {
        return true;
    }
    return false;
}

bool ScalarConverter::isInt(const std::string& literal) {
    if (literal.empty()) return false;
    size_t i = 0;
    if (literal[0] == '-' || literal[0] == '+') i++;
    for (; i < literal.length(); i++) {
        if (!isdigit(literal[i])) return false;
    }
    return true;
}

bool ScalarConverter::isFloat(const std::string& literal) {
    if (literal == "nanf" || literal == "+inff" || literal == "-inff") return true;
    if (literal.empty() || literal[literal.length() - 1] != 'f') return false;
    
    bool hasDecimal = false;
    size_t i = 0;
    if (literal[0] == '-' || literal[0] == '+') i++;
    
    for (; i < literal.length() - 1; i++) {
        if (literal[i] == '.') {
            if (hasDecimal) return false;
            hasDecimal = true;
        }
        else if (!isdigit(literal[i])) return false;
    }
    return hasDecimal;
}

bool ScalarConverter::isDouble(const std::string& literal) {
    if (literal == "nan" || literal == "+inf" || literal == "-inf") return true;
    
    bool hasDecimal = false;
    size_t i = 0;
    if (literal[0] == '-' || literal[0] == '+') i++;
    
    for (; i < literal.length(); i++) {
        if (literal[i] == '.') {
            if (hasDecimal) return false;
            hasDecimal = true;
        }
        else if (!isdigit(literal[i])) return false;
    }
    return hasDecimal;
}

bool ScalarConverter::isPseudoLiteral(const std::string& literal) {
    return literal == "nan" || literal == "nanf" ||
           literal == "+inf" || literal == "+inff" ||
           literal == "-inf" || literal == "-inff";
}

void ScalarConverter::convertFromChar(char c) {
    if (isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::convertFromInt(int i) {
    if (i >= 0 && i <= 127 && isprint(i))
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    else if (i >= 0 && i <= 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: impossible" << std::endl;
    
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void ScalarConverter::convertFromFloat(float f) {
    if (std::isnan(f) || std::isinf(f)) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    } else {
        if (f >= 0 && f <= 127 && isprint(static_cast<char>(f)))
            std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
        else if (f >= 0 && f <= 127)
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: impossible" << std::endl;
        
        if (f >= std::numeric_limits<int>::min() && f <= std::numeric_limits<int>::max())
            std::cout << "int: " << static_cast<int>(f) << std::endl;
        else
            std::cout << "int: impossible" << std::endl;
    }
    
    std::cout << "float: " << f;
    if (f == static_cast<int>(f))
        std::cout << ".0";
    std::cout << "f" << std::endl;
    
    std::cout << "double: " << static_cast<double>(f);
    if (f == static_cast<int>(f))
        std::cout << ".0";
    std::cout << std::endl;
}

void ScalarConverter::convertFromDouble(double d) {
    if (std::isnan(d) || std::isinf(d)) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    } else {
        if (d >= 0 && d <= 127 && isprint(static_cast<char>(d)))
            std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
        else if (d >= 0 && d <= 127)
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: impossible" << std::endl;
        
        if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
            std::cout << "int: " << static_cast<int>(d) << std::endl;
        else
            std::cout << "int: impossible" << std::endl;
    }
    
    std::cout << "float: " << static_cast<float>(d);
    if (d == static_cast<int>(d))
        std::cout << ".0";
    std::cout << "f" << std::endl;
    
    std::cout << "double: " << d;
    if (d == static_cast<int>(d))
        std::cout << ".0";
    std::cout << std::endl;
}

void ScalarConverter::convertFromPseudoLiteral(const std::string& literal) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    
    if (literal == "nan" || literal == "nanf") {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    } else if (literal == "+inf" || literal == "+inff") {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    } else if (literal == "-inf" || literal == "-inff") {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}

void ScalarConverter::convert(const std::string& literal) {
    if (isPseudoLiteral(literal)) {
        convertFromPseudoLiteral(literal);
    } else if (isChar(literal)) {
        convertFromChar(literal[0]);
    } else if (isInt(literal)) {
        convertFromInt(std::atoi(literal.c_str()));
    } else if (isFloat(literal)) {
        convertFromFloat(std::atof(literal.c_str()));
    } else if (isDouble(literal)) {
        convertFromDouble(std::atof(literal.c_str()));
    } else {
        std::cout << "Invalid input format" << std::endl;
    }
}
