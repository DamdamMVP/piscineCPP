#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
  Brain *brain;

public:
  Dog();
  Dog(const std::string &name);
  Dog(const Dog &other);
  Dog &operator=(const Dog &other);
  virtual ~Dog();

  std::string getBrainIdea(int i) const;
  void makeSound() const;
};