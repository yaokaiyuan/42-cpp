#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    static void fordJohnsonSortVector(std::vector<int>& data);
    static void fordJohnsonSortDeque(std::deque<int>& data);
};

#endif
