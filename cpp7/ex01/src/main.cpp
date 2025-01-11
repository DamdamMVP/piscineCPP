#include "iter.hpp"
#include <iostream>

int main() {
  int array[5] = {1, 2, 3, 4, 5};
  iter(array, 5, printElement<int>);

  std::string strArray[3] = {"Hello", "World", "!"};
  iter(strArray, 3, printElement<std::string>);

  return 0;
}
