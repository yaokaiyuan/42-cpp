#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <climits>

class Span {
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;

public:
    // Constructor
    Span(unsigned int N);
    
    // Copy constructor
    Span(const Span& other);
    
    // Assignment operator
    Span& operator=(const Span& other);
    
    // Destructor
    ~Span();
    
    // Member functions
    void addNumber(int number);
    int shortestSpan() const;
    int longestSpan() const;
    
    // Template function for adding range of iterators
    template<typename Iterator>
    void addRange(Iterator begin, Iterator end);
    
    // Getters for testing
    unsigned int getMaxSize() const;
    unsigned int getCurrentSize() const;
    const std::vector<int>& getNumbers() const;
};


template<typename Iterator>
void Span::addRange(Iterator begin, Iterator end) {
    unsigned int distance = std::distance(begin, end);
    if (_numbers.size() + distance > _maxSize) {
        throw std::runtime_error("Cannot add range: would exceed maximum size");
    }
    _numbers.insert(_numbers.end(), begin, end);
}

#endif
