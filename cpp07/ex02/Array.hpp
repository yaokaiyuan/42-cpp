#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <stdexcept>

// Array class template
template <typename T>
class Array {
public:
    Array();
    Array(unsigned int n);
    Array(const Array &other);
    Array &operator=(const Array &other);
    ~Array();

    T &operator[](unsigned int idx);
    const T &operator[](unsigned int idx) const;
    unsigned int size() const;

private:
    T *data;
    unsigned int _size;
};

#include "Array.tpp"

#endif
