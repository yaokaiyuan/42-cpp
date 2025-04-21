/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:12:54 by ykai-yua          #+#    #+#             */
/*   Updated: 2025/04/21 16:44:00 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
    Brain* brain;
public:
    Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    ~Cat();
    void makeSound() const;

    void setIdea(int index, const std::string& idea);
    std::string getIdea(int index) const;
};

#endif
