/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:59:37 by ykai-yua          #+#    #+#             */
/*   Updated: 2025/04/24 17:25:06 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type) {}
AMateria::~AMateria() {}
AMateria::AMateria(const AMateria& other) : _type(other._type) {}
AMateria& AMateria::operator=(const AMateria& other) {
    if (this != &other) {
        _type = other._type;
    }
    return *this;
}

std::string const & AMateria::getType() const {
    return _type;
}

void AMateria::use(ICharacter& target) {
    (void)target;
}
