#include "Span.hpp"

// Constructor
Span::Span(unsigned int N) : _maxSize(N) {
}

// Copy constructor
Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers) {
}

// Assignment operator
Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

// Destructor
Span::~Span() {
}

// Add a single number
void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize) {
        throw std::runtime_error("Cannot add number: Span is full");
    }
    _numbers.push_back(number);
}

// Find shortest span between any two numbers
int Span::shortestSpan() const {
    if (_numbers.size() < 2) {
        throw std::runtime_error("Cannot find span: need at least 2 numbers");
    }
    
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    
    int shortest = INT_MAX;
    for (size_t i = 1; i < sorted.size(); ++i) {
        int diff = sorted[i] - sorted[i-1];
        if (diff < shortest) {
            shortest = diff;
        }
    }
    
    return shortest;
}

// Find longest span between any two numbers
int Span::longestSpan() const {
    if (_numbers.size() < 2) {
        throw std::runtime_error("Cannot find span: need at least 2 numbers");
    }
    
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    
    return sorted.back() - sorted.front();
}

// Getters for testing
unsigned int Span::getMaxSize() const {
    return _maxSize;
}

unsigned int Span::getCurrentSize() const {
    return _numbers.size();
}

const std::vector<int>& Span::getNumbers() const {
    return _numbers;
}
