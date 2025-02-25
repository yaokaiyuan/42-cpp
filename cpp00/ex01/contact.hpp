/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:27:37 by ykai-yua          #+#    #+#             */
/*   Updated: 2025/02/25 14:27:40 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    void setContactInfo();
    void displayContact() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
};

#endif