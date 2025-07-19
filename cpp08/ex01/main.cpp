#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    std::cout << "=== Basic Test (Required Example) ===" << std::endl;
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
		std::cout << "Max size: " << sp.getMaxSize() << std::endl;
        std::cout << "Current size: " << sp.getCurrentSize() << std::endl;
		const std::vector<int>& nums = sp.getNumbers();
        std::cout << "Numbers stored: ";
        for (size_t i = 0; i < nums.size(); ++i)
            std::cout << nums[i] << " ";
        std::cout << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    
    std::cout << "\n=== Exception Tests ===" << std::endl;
    {
        // Test empty span
        Span sp1(5);
        try {
            std::cout << "Trying to get shortest span from empty span..." << std::endl;
            sp1.shortestSpan();
        } catch (const std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
        
        // Test single element span
        Span sp2(5);
        sp2.addNumber(42);
        try {
            std::cout << "Trying to get shortest span from single element..." << std::endl;
            sp2.shortestSpan();
        } catch (const std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
        
        // Test overflow
        Span sp3(3);
        sp3.addNumber(1);
        sp3.addNumber(2);
        sp3.addNumber(3);
        try {
            std::cout << "Trying to add number to full span..." << std::endl;
            sp3.addNumber(4);
        } catch (const std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
    }
    
    std::cout << "\n=== Large Scale Test (10,000+ numbers) ===" << std::endl;
    {
        Span sp(15000);
        std::srand(std::time(0));
        
        // Add 10,000 random numbers
        for (int i = 0; i < 10000; ++i) {
            sp.addNumber(std::rand() % 1000000);
        }
        
        std::cout << "Added 10,000 random numbers" << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
        
        // Add 5,000 more numbers using iterator range
        std::vector<int> moreNumbers;
        for (int i = 0; i < 5000; ++i) {
            moreNumbers.push_back(std::rand() % 1000000);
        }
        
        sp.addRange(moreNumbers.begin(), moreNumbers.end());
        std::cout << "Added 5,000 more numbers using iterator range" << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    
    std::cout << "\n=== Iterator Range Test ===" << std::endl;
    {
        Span sp(10);
        std::vector<int> numbers;
        numbers.push_back(1);
        numbers.push_back(5);
        numbers.push_back(10);
        numbers.push_back(15);
        numbers.push_back(20);
        
		std::cout << "Current size: " << sp.getCurrentSize() << std::endl;
        sp.addRange(numbers.begin(), numbers.end());
        std::cout << "Added range of 5 numbers" << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
        std::cout << "Current size: " << sp.getCurrentSize() << std::endl;
		
        // Try to add too many numbers
		std::cout << "Max size: " << sp.getMaxSize() << std::endl;
        std::vector<int> tooMany;
        tooMany.push_back(1);
        tooMany.push_back(2);
        tooMany.push_back(3);
        tooMany.push_back(4);
        tooMany.push_back(5);
        tooMany.push_back(6);
        try {
            sp.addRange(tooMany.begin(), tooMany.end());
        } catch (const std::exception& e) {
            std::cout << "Exception caught when adding too many numbers: " << e.what() << std::endl;
        }
    }
    
    std::cout << "\n=== Copy Constructor and Assignment Test ===" << std::endl;
    {
        Span original(5);
        original.addNumber(1);
        original.addNumber(5);
        original.addNumber(10);
        
        // Test copy constructor
        Span copy(original);
        std::cout << "Copy constructor - Shortest span: " << copy.shortestSpan() << std::endl;
        std::cout << "Copy constructor - Longest span: " << copy.longestSpan() << std::endl;
        
        // Test assignment operator
        Span assigned(3);
        assigned = original;
        std::cout << "Assignment operator - Shortest span: " << assigned.shortestSpan() << std::endl;
        std::cout << "Assignment operator - Longest span: " << assigned.longestSpan() << std::endl;
    }
    
    std::cout << "\n=== Edge Cases Test ===" << std::endl;
    {
        // Test with negative numbers
        Span sp(5);
        sp.addNumber(-10);
        sp.addNumber(-5);
        sp.addNumber(0);
        sp.addNumber(5);
        sp.addNumber(10);
        std::cout << "With negative numbers:" << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
        
        // Test with duplicate numbers
        Span sp2(5);
        sp2.addNumber(1);
        sp2.addNumber(1);
        sp2.addNumber(1);
        sp2.addNumber(2);
        sp2.addNumber(2);
        std::cout << "With duplicate numbers:" << std::endl;
        std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
    }
    
    return 0;
}
