#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
  std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const std::string &name) : Animal(name) {
  std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
  std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
  if (this != &other) {
    Animal::operator=(other);
  }
  std::cout << "Cat constructor called by operator" << std::endl;
  return *this;
}

Cat::~Cat() { std::cout << "Cat destructor called" << std::endl; }

void Cat::makeSound() const { std::cout << "Meow Meow!" << std::endl; }