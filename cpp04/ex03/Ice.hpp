/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:00:31 by ykai-yua          #+#    #+#             */
/*   Updated: 2025/04/24 19:45:24 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
public:
    Ice();
    virtual ~Ice();
	Ice(const Ice& other); // Copy constructor
    Ice& operator=(const Ice& other); // Assignment operator
    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);
};

#endif
