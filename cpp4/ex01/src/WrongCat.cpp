#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
  std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const std::string &name) : WrongAnimal(name) {
  std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
  std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
  if (this != &other) {
    WrongAnimal::operator=(other);
  }
  std::cout << "WrongCat constructor called by operator" << std::endl;
  return *this;
}

WrongCat::~WrongCat() {
  std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const {
  std::cout << "Meow? (Wrong sound)" << std::endl;
}