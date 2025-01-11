#pragma once

# include <iostream>
# include <sstream>
# include <vector>
# include <deque>
# include <cstdlib>
# include <algorithm>
#include <sys/time.h>

class PmergeMe {
  private:
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    std::vector<int> _vector;
    std::deque<int> _deque;
    std::vector<std::vector<int> > _vectors;
    std::deque<std::deque<int> > _deques;
    int _highest;
    int _totalSize;

    public :
    PmergeMe();
    ~PmergeMe();
    void parse(std::string str);
    template <typename T> void printData(const T &data) const;
    void sortAndMergeV();
    void findHighestV();
    void sortAndMergeD();
    void findHighestD();
};