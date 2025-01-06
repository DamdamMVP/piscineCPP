#pragma once
#include <iostream>

template <typename T> class Array {
private:
  T *_array;
  unsigned int _size;

public:
  Array();
  Array(const Array &other);
  ~Array();
  Array(const unsigned int n);
  Array &operator=(const Array &other);

  T &operator[](unsigned int index);
  unsigned int size() const;
};

#include "Array.tpp"