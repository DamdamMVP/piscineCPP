#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main() {
    std::vector<int> v;
    v.push_back(10);
    v.push_back(42);
    v.push_back(7);

    try {
        std::vector<int>::iterator it = easyfind(v, 42);
        std::cout << "Element found: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(v, 99);
        std::cout << "Element found: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
