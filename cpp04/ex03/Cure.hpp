/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:00:18 by ykai-yua          #+#    #+#             */
/*   Updated: 2025/04/24 19:45:32 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
public:
    Cure();
    virtual ~Cure();
	Cure(const Cure& other); // Copy constructor
    Cure& operator=(const Cure& other); // Assignment operator
    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);
};

#endif
