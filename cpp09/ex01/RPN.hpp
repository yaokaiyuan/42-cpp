#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <stdexcept>

class RPN {
private:
    std::string expr_;
public:
    RPN(const std::string& expr);
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();

    int evaluate();
};

#endif
