#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), brain(new Brain()) {
  std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const std::string &name) : Animal(name), brain(new Brain()) {
  std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other), brain(new Brain(*other.brain)) {
  std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
  if (this != &other) {
    Animal::operator=(other);
	delete brain;
	brain = new Brain(*other.brain);
  }
  std::cout << "Cat constructor called by operator" << std::endl;
  return *this;
}

Cat::~Cat() {
  std::cout << "Cat destructor called" << std::endl;
  delete brain;
}

void Cat::makeSound() const { std::cout << "Meow Meow!" << std::endl; }