#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
  std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &name) : type(name) {
  std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
  if (this != &other) {
    this->type = other.type;
  }
  std::cout << "WrongAnimal constructor called by operator" << std::endl;
  return *this;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const {
  std::cout << "Some generic wrong animal sound" << std::endl;
}

std::string WrongAnimal::getType() const { return type; }