/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:50:46 by ykai-yua          #+#    #+#             */
/*   Updated: 2025/07/07 16:30:10 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

// Test with complex type Awesome
class Awesome {
public:
    Awesome(void) : _n(0) {}
    Awesome(int n) : _n(n) {}
    Awesome &operator=(Awesome &a) { _n = a._n; return *this; }
    bool operator==(Awesome const &rhs) const { return (this->_n == rhs._n); }
    bool operator!=(Awesome const &rhs) const { return (this->_n != rhs._n); }
    bool operator>(Awesome const &rhs) const { return (this->_n > rhs._n); }
    bool operator<(Awesome const &rhs) const { return (this->_n < rhs._n); }
    bool operator>=(Awesome const &rhs) const { return (this->_n >= rhs._n); }
    bool operator<=(Awesome const &rhs) const { return (this->_n <= rhs._n); }
    int get_n() const { return _n; }
private:
    int _n;
};

std::ostream &operator<<(std::ostream &o, const Awesome &a) { o << a.get_n(); return o; }

int main( void ) {
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	
	int i = 0;
	int j = 0;
	std::cout << "i = " << i << ", j = " << j << std::endl;
	// Test if min returns the second one when equal
	if (&::min(i, j) == &j)
	    std::cout << "min(i, j) returns the second argument when equal (OK)" << std::endl;
	else
	    std::cout << "min(i, j) does NOT return the second argument when equal (FAIL)" << std::endl;

	// Test if max returns the second one when equal
	if (&::max(i, j) == &j)
	    std::cout << "max(i, j) returns the second argument when equal (OK)" << std::endl;
	else
	    std::cout << "max(i, j) does NOT return the second argument when equal (FAIL)" << std::endl;

    // Test with Awesome class
	Awesome awesomeA(2), awesomeB(4);
	::swap(awesomeA, awesomeB);
	std::cout << "a = " << awesomeA << ", b = " << awesomeB << std::endl;
	std::cout << "max(a, b) = " << ::max(awesomeA, awesomeB) << std::endl;
	std::cout << "min(a, b) = " << ::min(awesomeA, awesomeB) << std::endl;
	return 0;
}