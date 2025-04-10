/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 21:34:49 by ykai-yua          #+#    #+#             */
/*   Updated: 2025/04/10 21:36:38 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int					fixedPointValue;
    static const int	fractionalBits = 8;
public:
    Fixed();
    Fixed(const int);
    Fixed(const float);
    Fixed(const Fixed&);
    Fixed& operator=(const Fixed&);
    ~Fixed();

    int getRawBits() const;
    void setRawBits(int const raw);
    float toFloat() const;
    int toInt() const;

    bool operator>(const Fixed&) const;
    bool operator<(const Fixed&) const;
    bool operator>=(const Fixed&) const;
    bool operator<=(const Fixed&) const;
    bool operator==(const Fixed&) const;
    bool operator!=(const Fixed&) const;

    Fixed operator+(const Fixed&) const;
    Fixed operator-(const Fixed&) const;
    Fixed operator*(const Fixed&) const;
    Fixed operator/(const Fixed&) const;

    Fixed& operator++();      // pre
    Fixed operator++(int);    // post
    Fixed& operator--();
    Fixed operator--(int);

    static Fixed& min(Fixed&, Fixed&);
    static const Fixed& min(const Fixed&, const Fixed&);
    static Fixed& max(Fixed&, Fixed&);
    static const Fixed& max(const Fixed&, const Fixed&);
};

std::ostream& operator<<(std::ostream& out, const Fixed& f);

#endif
