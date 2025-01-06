#pragma once

#include <algorithm>  // Pour std::find
#include <exception>  // Pour std::exception

// Exception personnalisée
class NotFoundException : public std::exception {
public:
    const char* what() const throw() {
        return "Element not found";
    }
};

// Template easyfind
template <typename T>
typename T::iterator easyfind(T& container, const int &nb) {
    typename T::iterator it = std::find(container.begin(), container.end(), nb);
    if (it == container.end()) {
        throw NotFoundException();
    }
    return it;
}
