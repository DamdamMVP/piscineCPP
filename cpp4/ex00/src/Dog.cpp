#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
  std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const std::string &name) : Animal(name) {
  std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
  std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
  if (this != &other) {
    Animal::operator=(other);
  }
  std::cout << "Dog constructor called by operator" << std::endl;
  return *this;
}

Dog::~Dog() { std::cout << "Dog destructor called" << std::endl; }

void Dog::makeSound() const { std::cout << "Woof Woof!" << std::endl; }