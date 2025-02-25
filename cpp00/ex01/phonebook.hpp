/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:28:20 by ykai-yua          #+#    #+#             */
/*   Updated: 2025/02/25 14:28:23 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"

class PhoneBook {
private:
    Contact contacts[8];
    int contactCount;

public:
    PhoneBook();
    void addContact();
    void searchContacts() const;
};

#endif