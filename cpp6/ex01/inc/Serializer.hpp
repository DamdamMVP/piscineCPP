#pragma once
#include <iostream>
#include <stdint.h>

struct Data {
  int value;
  std::string name;
};

class Serializer {
private:
  Serializer();
  Serializer(const Serializer &src);
  Serializer &operator=(const Serializer &rhs);
  ~Serializer() {};

public:
  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);
};