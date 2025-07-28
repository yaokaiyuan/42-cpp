#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <ctime>
#include <cstdlib>

static bool isPositiveInteger(const std::string& s) {
    if (s.empty()) return false;
    for (size_t i = 0; i < s.size(); ++i) {
        if (!isdigit(s[i])) return false;
    }
    return s[0] != '0' || s.size() == 1;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    std::vector<int> vec;
    std::deque<int> deq;
    for (int i = 1; i < argc; ++i) {
        std::string arg(argv[i]);
        if (!isPositiveInteger(arg)) {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        int val = std::atoi(argv[i]);
        if (val <= 0) {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        vec.push_back(val);
        deq.push_back(val);
    }
    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << (i + 1 < vec.size() ? " " : "\n");

    clock_t start_vec = clock();
    PmergeMe::fordJohnsonSortVector(vec);
    clock_t end_vec = clock();

    clock_t start_deq = clock();
    PmergeMe::fordJohnsonSortDeque(deq);
    clock_t end_deq = clock();

    std::cout << "After: ";
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << (i + 1 < vec.size() ? " " : "\n");

    double time_vec = 1e6 * (end_vec - start_vec) / CLOCKS_PER_SEC;
    double time_deq = 1e6 * (end_deq - start_deq) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << time_vec << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : " << time_deq << " us" << std::endl;
    return 0;
}
