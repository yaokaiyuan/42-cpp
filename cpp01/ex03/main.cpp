/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:02:25 by ykai-yua          #+#    #+#             */
/*   Updated: 2025/04/10 14:30:13 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
	{
		Weapon misslie = Weapon("misslie");
		HumanA bc("bombardino crocodilo", misslie);
		bc.attack();
		misslie.setType("lazer beam");
		bc.attack();
	}
	{
		HumanB ts("tun tun tun tun tun sahur");
		ts.attack();
		Weapon club("wooden club");
		ts.setWeapon(club);
		ts.attack();
	}
    return 0;
}
