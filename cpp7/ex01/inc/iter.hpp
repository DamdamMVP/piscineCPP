#pragma once
#include <stddef.h>
#include <iostream>

template <typename T> void printElement(T const &element) {
  std::cout << element << std::endl;
}

template <typename T>
void iter(T *array, size_t length, void (*f)(T const &)) {
  for (size_t i = 0; i < length; i++) {
    f(array[i]);
  }
}
