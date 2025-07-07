/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:41:43 by ykai-yua          #+#    #+#             */
/*   Updated: 2025/07/07 17:18:49 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

class Awesome {
public:
    Awesome(void) : _n(42) { return; }
    int get(void) const { return this->_n; }
private:
    int _n;
};

std::ostream &operator<<(std::ostream &o, Awesome const &rhs) { o << rhs.get(); return o; }

template <typename T>
void print(T const &x) { std::cout << "local print:"<< x << std::endl; return; }

int main() {
    int tab[] = { 0, 1, 2, 3, 4 };
    Awesome tab2[5];
    ::iter(tab, 5, ::print<int>);
    ::iter(tab2, 5, ::print<Awesome>);
    return 0;
}
