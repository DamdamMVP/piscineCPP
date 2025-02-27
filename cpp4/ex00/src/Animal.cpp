#include "Animal.hpp"

Animal::Animal() : type("Animal") {
  std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const std::string &name) : type(name) {
  std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type) {
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
  if (this != &other) {
    this->type = other.type;
  }
  std::cout << "Animal constructor called by operator" << std::endl;
  return *this;
}

Animal::~Animal() { std::cout << "Animal destructor called" << std::endl; }

void Animal::makeSound() const {
  std::cout << "Some generic animal sound" << std::endl;
}

std::string Animal::getType() const { return type; }
