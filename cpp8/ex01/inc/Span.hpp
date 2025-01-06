#pragma once

#include <vector>
#include <algorithm>
#include <exception>
#include <iostream>

class Span {
private:
    std::vector<int> numbers;
    unsigned int max_size;

public:
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int number);
    int shortestSpan() const;
    int longestSpan() const;
};
