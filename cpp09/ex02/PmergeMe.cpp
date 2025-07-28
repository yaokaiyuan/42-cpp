#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) { (void)other; }
PmergeMe& PmergeMe::operator=(const PmergeMe& other) { (void)other; return *this; }
PmergeMe::~PmergeMe() {}

// Helper for vector: binary insert
static void binaryInsertVector(std::vector<int>& sorted, int value) {
    std::vector<int>::iterator it = sorted.begin();
    std::vector<int>::iterator end = sorted.end();
    while (it < end) {
        std::vector<int>::iterator mid = it + (end - it) / 2;
        if (*mid < value)
            it = mid + 1;
        else
            end = mid;
    }
    sorted.insert(it, value);
}

void PmergeMe::fordJohnsonSortVector(std::vector<int>& data) {
    size_t n = data.size();
    if (n <= 1) return;
    // Step 1: Pair up and sort each pair
    std::vector<int> big, small;
    size_t i = 0;
    for (; i + 1 < n; i += 2) {
        if (data[i] < data[i+1]) {
            small.push_back(data[i]);
            big.push_back(data[i+1]);
        } else {
            small.push_back(data[i+1]);
            big.push_back(data[i]);
        }
    }
    int last = -1;
    if (n % 2) last = data[n-1];
    // Step 2: Recursively sort bigs
    fordJohnsonSortVector(big);
    // Step 3: Insert smalls into sorted bigs
    std::vector<int> result = big;
    for (size_t j = 0; j < small.size(); ++j) {
        binaryInsertVector(result, small[j]);
    }
    if (last != -1) {
        binaryInsertVector(result, last);
    }
    data = result;
}

// Helper for deque: binary insert
static void binaryInsertDeque(std::deque<int>& sorted, int value) {
    std::deque<int>::iterator it = sorted.begin();
    std::deque<int>::iterator end = sorted.end();
    while (it < end) {
        std::deque<int>::iterator mid = it + (end - it) / 2;
        if (*mid < value)
            it = mid + 1;
        else
            end = mid;
    }
    sorted.insert(it, value);
}

void PmergeMe::fordJohnsonSortDeque(std::deque<int>& data) {
    size_t n = data.size();
    if (n <= 1) return;
    // Step 1: Pair up and sort each pair
    std::deque<int> big, small;
    size_t i = 0;
    for (; i + 1 < n; i += 2) {
        if (data[i] < data[i+1]) {
            small.push_back(data[i]);
            big.push_back(data[i+1]);
        } else {
            small.push_back(data[i+1]);
            big.push_back(data[i]);
        }
    }
    int last = -1;
    if (n % 2) last = data[n-1];
    // Step 2: Recursively sort bigs
    fordJohnsonSortDeque(big);
    // Step 3: Insert smalls into sorted bigs
    std::deque<int> result = big;
    for (size_t j = 0; j < small.size(); ++j) {
        binaryInsertDeque(result, small[j]);
    }
    if (last != -1) {
        binaryInsertDeque(result, last);
    }
    data = result;
}
