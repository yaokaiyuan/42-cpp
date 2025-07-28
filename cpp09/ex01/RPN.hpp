#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <stdexcept>

class RPN {
public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();
    // Evaluates the RPN expression, throws std::runtime_error on error
    static int evaluate(const std::string& expr);
};

#endif
