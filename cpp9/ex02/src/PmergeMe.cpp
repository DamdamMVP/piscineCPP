#include "PmergeMe.hpp"
#include <algorithm>
#include <cstdlib>

PmergeMe::PmergeMe() : _highest(-1) {

}

PmergeMe::~PmergeMe() {
}

template <typename T> void PmergeMe::printData(const T &data) const {
  for (typename T::const_iterator it = data.begin(); it != data.end();
       ++it) {
    std::cout << *it << " ";
  }
}

static int isValid(std::string str) {
    std::string::iterator it = str.begin();
    int i = 0;
	while (*it == '0'){
		it++;
	}
    while (it != str.end())
    {
        if (!std::isdigit(*it))
        {
            return 0;
        }
        it++;
        i++;
    }
    if (i >= 11)
        return 0;
    return 1;
}

void PmergeMe::parse(std::string str) {
    std::stringstream ss(str);
    std::string token;
    int i = 0;
    while (ss >> token)
   {
    if (isValid(token))
        {
            _deque.push_back(atoi(token.c_str()));
            _vector.push_back(atoi(token.c_str()));
        } else
        {
            _vector.clear();
            _deque.clear();
            throw std::runtime_error("Error: Invalid token");
            return;
        }
        i++;
    }
    std::cout << "Before: [ ";
    printData(_vector);
    std::cout << "]" << std::endl;
    _totalSize = i;
}

void PmergeMe::findHighestV()
{
    int highest = 0;
    std::vector<int>::iterator it = _vector.begin();
    for (; it != _vector.end(); it++)
    {
        if (*it > highest)
            highest = *it;
    }
    _highest = highest;
    std::vector<int>::iterator itdel = std::find(_vector.begin(), _vector.end(), highest);
    _vector.erase(itdel);
}

void PmergeMe::sortAndMergeV()
{
    struct timeval start, end;
    gettimeofday(&start, NULL);
    if (_vector.size() == 1)
    {
        gettimeofday(&end, NULL);
        long long elapsedMicroseconds = (end.tv_sec - start.tv_sec) * 1000000LL + (end.tv_usec - start.tv_usec);
        std::cout << "after: [ ";
        printData(_vector);
        std::cout << "]" << std::endl;
        std::cout << "Time to process a range of "<< _totalSize << " elements with std::vector: " << elapsedMicroseconds << "µs" << std::endl;
        return;
    }
    if (_vector.size() % 2 != 0)
    {
        findHighestV();
    }
    while(!_vector.empty())
    {
        std::vector<int> pair;
        for (int j = 0; j < 2; ++j)
        {
            pair.push_back(_vector.front());
            _vector.erase(_vector.begin());
        }
        std::sort(pair.begin(), pair.end());
        _vectors.push_back(pair);
    }
    long unsigned int a = 0;
    long unsigned int b = 1;

    while(_vectors.size() != 1)
    {
        std::vector<int> tmp;
        bool isSameSize = false;
        a = 0;
        b = 1;
        while(b < _vectors.size())
        {
            if (_vectors[a].size() == _vectors[b].size())
            {
                isSameSize = true;
                break;
            }
            a++;
            b++;
        }
        if (!isSameSize)
            a = 0, b = 1;
        long unsigned int size = _vectors[a].size() + _vectors[b].size();
        while (size != 0)
        {
            if(_vectors[a].front() <= _vectors[b].front())
            {
                tmp.push_back(_vectors[a].front());
                size--;
                _vectors[a].erase(_vectors[a].begin());
                if (_vectors[a].empty())
                {
                    while(!_vectors[b].empty())
                    {
                        tmp.push_back(_vectors[b].front());
                        size--;
                        _vectors[b].erase(_vectors[b].begin());
                    }
                }
            }
            else
            {
                tmp.push_back(_vectors[b].front());
                size--;
                _vectors[b].erase(_vectors[b].begin());
                if (_vectors[b].empty())
                {
                    while(!_vectors[a].empty())
                    {
                        tmp.push_back(_vectors[a].front());
                        size--;
                        _vectors[a].erase(_vectors[a].begin());
                    }
                }
            }
        }
        _vectors.erase(_vectors.begin() + a);
        _vectors.erase(_vectors.begin() + a);
        _vectors.push_back(tmp);
    }
    _vector = _vectors[0];
    _vectors.clear();
    if (_highest != -1)
        _vector.push_back(_highest);
    gettimeofday(&end, NULL);
    long long elapsedMicroseconds = (end.tv_sec - start.tv_sec) * 1000000LL + (end.tv_usec - start.tv_usec);
    std::cout << "after: [ ";
    printData(_vector);
    std::cout << "]" << std::endl;
    std::cout << "Time to process a range of "<< _totalSize << " elements with std::vector: " << elapsedMicroseconds << "µs" << std::endl;
}


void PmergeMe::findHighestD()
{
    int highest = 0;
    std::deque<int>::iterator it = _deque.begin();
    for (; it != _deque.end(); it++)
    {
        if (*it > highest)
            highest = *it;
    }
    _highest = highest;
    std::deque<int>::iterator itdel = std::find(_deque.begin(), _deque.end(), highest);
    _deque.erase(itdel);
}

void PmergeMe::sortAndMergeD()
{
    struct timeval start, end;
    gettimeofday(&start, NULL);
    if (_deque.size() == 1)
    {
        gettimeofday(&end, NULL);
        long long elapsedMicroseconds = (end.tv_sec - start.tv_sec) * 1000000LL + (end.tv_usec - start.tv_usec);
        std::cout << "Time to process a range of "<< _totalSize << " elements with std::deque: " << elapsedMicroseconds << "µs" << std::endl;
        return;
    }
    if (_deque.size() % 2 != 0)
    {
        findHighestD();
    }
    while(!_deque.empty())
    {
        std::deque<int> pair;
        for (int j = 0; j < 2; ++j)
        {
            pair.push_back(_deque.front());
            _deque.erase(_deque.begin());
        }
        std::sort(pair.begin(), pair.end());
        _deques.push_back(pair);
    }
    long unsigned int a = 0;
    long unsigned int b = 1;

    while(_deques.size() != 1)
    {
        std::deque<int> tmp;
        bool isSameSize = false;
        a = 0;
        b = 1;
        while(b < _deques.size())
        {
            if (_deques[a].size() == _deques[b].size())
            {
                isSameSize = true;
                break;
            }
            a++;
            b++;
        }
        if (!isSameSize)
            a = 0, b = 1;
        long unsigned int size = _deques[a].size() + _deques[b].size();
        while (size != 0)
        {
            if(_deques[a].front() <= _deques[b].front())
            {
                tmp.push_back(_deques[a].front());
                size--;
                _deques[a].erase(_deques[a].begin());
                if (_deques[a].empty())
                {
                    while(!_deques[b].empty())
                    {
                        tmp.push_back(_deques[b].front());
                        size--;
                        _deques[b].erase(_deques[b].begin());
                    }
                }
            }
            else
            {
                tmp.push_back(_deques[b].front());
                size--;
                _deques[b].erase(_deques[b].begin());
                if (_deques[b].empty())
                {
                    while(!_deques[a].empty())
                    {
                        tmp.push_back(_deques[a].front());
                        size--;
                        _deques[a].erase(_deques[a].begin());
                    }
                }
            }
        }
        _deques.erase(_deques.begin() + a);
        _deques.erase(_deques.begin() + a);
        _deques.push_back(tmp);
    }
    _deque = _deques[0];
    _deques.clear();
    if (_highest != -1)
        _deque.push_back(_highest);
    gettimeofday(&end, NULL);
    long long elapsedMicroseconds = (end.tv_sec - start.tv_sec) * 1000000LL + (end.tv_usec - start.tv_usec);
    std::cout << "Time to process a range of "<< _totalSize << " elements with std::deque: " << elapsedMicroseconds << "µs" << std::endl;
}