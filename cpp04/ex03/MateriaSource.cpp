/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:01:06 by ykai-yua          #+#    #+#             */
/*   Updated: 2025/04/24 19:14:51 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; ++i)
        _templates[i] = NULL;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; ++i)
        delete _templates[i];
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    for (int i = 0; i < 4; ++i)
        _templates[i] = other._templates[i] ? other._templates[i]->clone() : NULL;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            delete _templates[i];
            _templates[i] = other._templates[i] ? other._templates[i]->clone() : NULL;
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
    if (!m) return;
    for (int i = 0; i < 4; ++i) {
        if (!_templates[i]) {
            _templates[i] = m->clone();
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; ++i) {
        if (_templates[i] && _templates[i]->getType() == type)
            return _templates[i]->clone();
    }
    return NULL;
}
