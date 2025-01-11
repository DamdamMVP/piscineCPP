#include "PmergeMe.hpp"

int main (int ac, char **av)
{
    if (ac == 1)
    {
        std::cout << "Error: not enough arguments" << std::endl;
        return 1;
    }
    std::string str;
    for (int i = 1; i < ac; i++)
    {
        str += av[i];
        str += " ";
    }
    PmergeMe p;
    try {
        p.parse(str);
        p.sortAndMergeV();
        p.sortAndMergeD();
    } catch (...) {
        std::cerr << "Error: Invalid Token" << std::endl;
        return 1;
    }
    return 0;
}