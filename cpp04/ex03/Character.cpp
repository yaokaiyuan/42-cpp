/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:59:56 by ykai-yua          #+#    #+#             */
/*   Updated: 2025/04/24 19:53:56 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character(std::string const & name) : _name(name), _floorCount(0) {
    for (int i = 0; i < 4; ++i)
        _inventory[i] = NULL;
    for (int i = 0; i < 100; ++i)
        _floor[i] = NULL;
}

Character::~Character() {
    for (int i = 0; i < 4; ++i)
        delete _inventory[i];
    for (int i = 0; i < _floorCount; ++i)
        delete _floor[i];
}

Character::Character(const Character& other) : _name(other._name), _floorCount(0) {
    for (int i = 0; i < 4; ++i) {
        _inventory[i] = other._inventory[i] ? other._inventory[i]->clone() : NULL;
    }
    for (int i = 0; i < 100; ++i)
        _floor[i] = NULL;
}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            delete _inventory[i];
            _inventory[i] = other._inventory[i] ? other._inventory[i]->clone() : NULL;
        }
    }
    return *this;
}

std::string const & Character::getName() const {
    return _name;
}

void Character::equip(AMateria* m) {
    if (!m) return;
    for (int i = 0; i < 4; ++i) {
        if (!_inventory[i]) {
            _inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= 4 || !_inventory[idx]) return;
    if (_floorCount < 100)
        _floor[_floorCount++] = _inventory[idx];
    _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= 4 || !_inventory[idx]) return;
    _inventory[idx]->use(target);
}
