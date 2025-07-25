#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main() {
    std::cout << "=== MutantStack Test ===" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    // [...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    std::cout << "\n=== std::list Comparison ===" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << lst.back() << std::endl;
    lst.pop_back();
    std::cout << lst.size() << std::endl;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    std::list<int>::iterator lit = lst.begin();
    std::list<int>::iterator lite = lst.end();
    ++lit;
    --lit;
    while (lit != lite) {
        std::cout << *lit << std::endl;
        ++lit;
    }

	std::cout << "=== Test const_iterator ===" << std::endl;
    const MutantStack<int> cmstack = mstack; // const copy
    MutantStack<int>::const_iterator cit = cmstack.begin();
    MutantStack<int>::const_iterator cite = cmstack.end();
    while (cit != cite) {
        std::cout << *cit << " ";
		++cit;
    }
    std::cout << std::endl;

    std::cout << "=== Test reverse_iterator ===" << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    while (rit != rite) {
        std::cout << *rit << " ";
		++rit;
    }
    std::cout << std::endl;

    std::cout << "=== Test const_reverse_iterator ===" << std::endl;
    MutantStack<int>::const_reverse_iterator crit = cmstack.rbegin();
    MutantStack<int>::const_reverse_iterator crite = cmstack.rend();
    while (crit != crite) {
        std::cout << *crit << " ";
		++crit;
    }
    std::cout << std::endl;

    return 0;
}
