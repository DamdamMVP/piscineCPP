#pragma once
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
  WrongCat();
  WrongCat(const std::string &name);
  WrongCat(const WrongCat &other);
  WrongCat &operator=(const WrongCat &other);
  ~WrongCat();
  void makeSound() const;
};