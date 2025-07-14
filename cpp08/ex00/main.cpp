#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

void test_vector() {
    int arr[] = {1, 2, 3, 4, 5};
    std::vector<int> v(arr, arr + 5);
    try {
        std::vector<int>::const_iterator it = easyfind(v, 3);
        std::cout << "Found in vector: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        std::vector<int>::const_iterator it = easyfind(v, 42);
        std::cout << "Found in vector: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void test_list() {
    int arr[] = {10, 20, 30, 40};
    std::list<int> l(arr, arr + 4);
    try {
        std::list<int>::const_iterator it = easyfind(l, 20);
        std::cout << "Found in list: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        std::list<int>::const_iterator it = easyfind(l, 99);
        std::cout << "Found in list: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void test_deque() {
    int arr[] = {7, 8, 9};
    std::deque<int> d(arr, arr + 3);
    try {
        std::deque<int>::const_iterator it = easyfind(d, 8);
        std::cout << "Found in deque: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        std::deque<int>::const_iterator it = easyfind(d, 0);
        std::cout << "Found in deque: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

int main() {
    test_vector();
    test_list();
    test_deque();
    return 0;
}
