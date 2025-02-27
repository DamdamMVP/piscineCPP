#pragma once
#include "Animal.hpp"

class Cat : public Animal {
public:
  Cat();
  Cat(const std::string &name);
  Cat(const Cat &other);
  Cat &operator=(const Cat &other);
  virtual ~Cat();
  virtual void makeSound() const;
};