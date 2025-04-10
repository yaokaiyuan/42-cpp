/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 20:44:59 by ykai-yua          #+#    #+#             */
/*   Updated: 2025/04/10 21:07:51 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int                 fixedPointValue;
    static const int    fractionalBits = 8;

public:
    Fixed();                              // Default constructor
    Fixed(const int value);              // From int
    Fixed(const float value);            // From float
    Fixed(const Fixed& other);           // Copy constructor
    ~Fixed();                             // Destructor

    Fixed& operator=(const Fixed& other); // Copy assignment

    int     getRawBits() const;
    void    setRawBits(int const raw);
    float   toFloat() const;
    int     toInt() const;

    // Comparison operators
    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

    // Arithmetic operators
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    // Increment/Decrement
    Fixed& operator++();      // Pre-increment
    Fixed operator++(int);    // Post-increment
    Fixed& operator--();      // Pre-decrement
    Fixed operator--(int);    // Post-decrement

    // Static min/max
    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
