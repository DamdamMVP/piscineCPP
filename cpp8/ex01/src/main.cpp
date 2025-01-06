#include "Span.hpp"
#include <iostream>

int main() {
    Span sp = Span(5);

    sp.addNumber(-1);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    try {
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    Span spv2 = Span(10000);
    for (int i = 0; i < 10000; i++) {
        spv2.addNumber(i);
    }

    try {
        std::cout << "Shortest Span: " << spv2.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << spv2.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
