/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 20:25:09 by ykai-yua          #+#    #+#             */
/*   Updated: 2025/04/10 20:29:32 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    fixedPointValue = value << fractionalBits;
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    fixedPointValue = static_cast<int>(roundf(value * (1 << fractionalBits)));
}

Fixed::Fixed(const Fixed& other) : fixedPointValue(other.fixedPointValue) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->fixedPointValue = other.fixedPointValue;
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    return this->fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    this->fixedPointValue = raw;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(fixedPointValue) / (1 << fractionalBits);
}

int Fixed::toInt(void) const {
    return fixedPointValue >> fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}