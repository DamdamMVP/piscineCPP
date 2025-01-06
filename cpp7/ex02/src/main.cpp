#include "Array.hpp"
#include "Array.tpp"

int main() {
    try {
        Array<int> arr(5);
        for (unsigned int i = 0; i < arr.size(); i++) {
            arr[i] = i * 10;
            std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
        }

        // Test d'accès hors limites
        std::cout << arr[10] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
