#include "Span.hpp"
#include <iostream>

int main() {
  Span sp = Span(10000);

  try {
    sp.generateNumbers(10000);
    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  Span spv2(10000);

  try {
    spv2.generateNumbers(10001);
    std::cout << "Shortest Span: " << spv2.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << spv2.longestSpan() << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
