#include "Span.hpp"

Span::Span(unsigned int N) : max_size(N) {}

Span::Span(const Span& other) : numbers(other.numbers), max_size(other.max_size) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        numbers = other.numbers;
        max_size = other.max_size;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (numbers.size() >= max_size) {
        throw std::overflow_error("Span is full, cannot add more numbers.");
    }
    numbers.push_back(number);
}

int Span::longestSpan() const {
    if (numbers.size() < 2) {
        throw std::runtime_error("Not enough numbers to calculate span.");
    }
    int max = *std::max_element(numbers.begin(), numbers.end());
    int min = *std::min_element(numbers.begin(), numbers.end());
    return max - min;
}

int Span::shortestSpan() const {
    if (numbers.size() < 2) {
        throw std::runtime_error("Not enough numbers to calculate span.");
    }

    std::vector<int> sorted = numbers;
    std::sort(sorted.begin(), sorted.end());

    int min_diff = sorted[1] - sorted[0];
    for (size_t i = 1; i < sorted.size() - 1; ++i) {
        int diff = sorted[i + 1] - sorted[i];
        if (diff < min_diff) {
            min_diff = diff;
        }
    }
    return min_diff;
}
