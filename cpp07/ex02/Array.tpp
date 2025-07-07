#pragma once

#include "Array.hpp"

// Default constructor: empty array
template <typename T>
Array<T>::Array() : data(0), _size(0) {}

// Constructor with size
template <typename T>
Array<T>::Array(unsigned int n) : data(0), _size(n) {
    if (n > 0)
        data = new T[n](); // value-initialized
}

// Copy constructor
template <typename T>
Array<T>::Array(const Array &other) : data(0), _size(other._size) {
    if (_size > 0) {
        data = new T[_size]();
        for (unsigned int i = 0; i < _size; ++i)
            data[i] = other.data[i];
    }
}

// Assignment operator
template <typename T>
Array<T> &Array<T>::operator=(const Array &other) {
    if (this != &other) {
        delete[] data;
        _size = other._size;
        data = (_size > 0) ? new T[_size]() : 0;
        for (unsigned int i = 0; i < _size; ++i)
            data[i] = other.data[i];
    }
    return *this;
}

// Destructor
template <typename T>
Array<T>::~Array() {
    delete[] data;
}

// Subscript operator (non-const)
template <typename T>
T &Array<T>::operator[](unsigned int idx) {
    if (idx >= _size)
        throw std::out_of_range("Array index out of bounds");
    return data[idx];
}

// Subscript operator (const)
template <typename T>
const T &Array<T>::operator[](unsigned int idx) const {
    if (idx >= _size)
        throw std::out_of_range("Array index out of bounds");
    return data[idx];
}

// size() member
template <typename T>
unsigned int Array<T>::size() const {
    return _size;
} 