/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 20:45:05 by ykai-yua          #+#    #+#             */
/*   Updated: 2025/04/10 21:08:33 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

// Constructors
Fixed::Fixed() : fixedPointValue(0) {}
Fixed::Fixed(const int value) : fixedPointValue(value << fractionalBits) {}
Fixed::Fixed(const float value) : fixedPointValue(roundf(value * (1 << fractionalBits))) {}
Fixed::Fixed(const Fixed& other) { *this = other; }
Fixed::~Fixed() {}

// Assignment
Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other)
        fixedPointValue = other.fixedPointValue;
    return *this;
}

// Conversion
int Fixed::getRawBits() const { return fixedPointValue; }
void Fixed::setRawBits(int const raw) { fixedPointValue = raw; }
float Fixed::toFloat() const { return (float)fixedPointValue / (1 << fractionalBits); }
int Fixed::toInt() const { return fixedPointValue >> fractionalBits; }

// Stream output
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}

// Comparison operators
bool Fixed::operator>(const Fixed& other) const { return fixedPointValue > other.fixedPointValue; }
bool Fixed::operator<(const Fixed& other) const { return fixedPointValue < other.fixedPointValue; }
bool Fixed::operator>=(const Fixed& other) const { return fixedPointValue >= other.fixedPointValue; }
bool Fixed::operator<=(const Fixed& other) const { return fixedPointValue <= other.fixedPointValue; }
bool Fixed::operator==(const Fixed& other) const { return fixedPointValue == other.fixedPointValue; }
bool Fixed::operator!=(const Fixed& other) const { return fixedPointValue != other.fixedPointValue; }

// Arithmetic operators
Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result.fixedPointValue = fixedPointValue + other.fixedPointValue;
    return result;
}
Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result.fixedPointValue = fixedPointValue - other.fixedPointValue;
    return result;
}
Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    result.fixedPointValue = (fixedPointValue * other.fixedPointValue) >> fractionalBits;
    return result;
}
Fixed Fixed::operator/(const Fixed& other) const {
    Fixed result;
    result.fixedPointValue = (fixedPointValue << fractionalBits) / other.fixedPointValue;
    return result;
}

// Pre/Post increment
Fixed& Fixed::operator++() {
    ++fixedPointValue;
    return *this;
}
Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++fixedPointValue;
    return temp;
}
Fixed& Fixed::operator--() {
    --fixedPointValue;
    return *this;
}
Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --fixedPointValue;
    return temp;
}

// Min/Max functions
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}
Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}
