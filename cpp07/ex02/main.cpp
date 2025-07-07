#include <iostream>
#include "Array.hpp"

class Awesome {
public:
    Awesome() : _n(42) {}
    Awesome(int n) : _n(n) {}
    int get() const { return _n; }
private:
    int _n;
};

std::ostream &operator<<(std::ostream &o, const Awesome &a) { return o << a.get(); }

int main() {
    // Default construction
    Array<int> a;
    std::cout << "a.size() = " << a.size() << std::endl;

    // Construction with size
    Array<int> b(5);
    std::cout << "b.size() = " << b.size() << std::endl;
    for (unsigned int i = 0; i < b.size(); ++i)
        std::cout << "b[" << i << "] = " << b[i] << std::endl;

    // Modify and check copy constructor
    b[0] = 10;
    b[1] = 20;
    Array<int> c = b;
    c[1] = 99;
    std::cout << "b[1] = " << b[1] << ", c[1] = " << c[1] << std::endl;

    // Assignment operator
    Array<int> d;
    d = b;
    d[0] = 77;
    std::cout << "b[0] = " << b[0] << ", d[0] = " << d[0] << std::endl;

    // Const correctness
    const Array<int> e(b);
    std::cout << "e[2] = " << e[2] << std::endl;

    // Bounds checking
    try {
        std::cout << b[5] << std::endl;
    } catch (const std::exception &ex) {
        std::cout << "Exception: " << ex.what() << std::endl;
    }

    // Test with custom class
    Array<Awesome> f(3);
    for (unsigned int i = 0; i < f.size(); ++i)
        f[i] = Awesome(i);
    for (unsigned int i = 0; i < f.size(); ++i)
        std::cout << "f[" << i << "] = " << f[i] << std::endl;

    return 0;
}
