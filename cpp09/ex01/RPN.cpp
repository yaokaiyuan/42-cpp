#include "RPN.hpp"
#include <sstream>
#include <cctype>

RPN::RPN() {}
RPN::RPN(const RPN& other) {}
RPN& RPN::operator=(const RPN& other) { return *this; }
RPN::~RPN() {}

int RPN::evaluate(const std::string& expr) {
    std::stack<int> stack;
    std::istringstream iss(expr);
    std::string token;
    while (iss >> token) {
        if (token.size() == 1 && std::isdigit(token[0])) {
            stack.push(token[0] - '0');
        } else if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (stack.size() < 2)
                throw std::runtime_error("Error");
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            int res = 0;
            if (token == "+") res = a + b;
            else if (token == "-") res = a - b;
            else if (token == "*") res = a * b;
            else if (token == "/") {
                if (b == 0) throw std::runtime_error("Error");
                res = a / b;
            }
            stack.push(res);
        } else {
            throw std::runtime_error("Error");
        }
    }
    if (stack.size() != 1)
        throw std::runtime_error("Error");
    return stack.top();
}
