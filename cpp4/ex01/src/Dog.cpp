#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), brain(new Brain()) {
  std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const std::string &name) : Animal(name), brain(new Brain()) {
  std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other), brain(new Brain(*other.brain)) {
  std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
  if (this != &other) {
    Animal::operator=(other);
	delete brain;
	brain = new Brain(*other.brain);
  }
  std::cout << "Dog constructor called by operator" << std::endl;
  return *this;
}

std::string Dog::getBrainIdea(int i) const {
	return brain->getIdea(i);
}

Dog::~Dog() {
  std::cout << "Dog destructor called" << std::endl;
  delete brain;
}

void Dog::makeSound() const { std::cout << "Woof Woof!" << std::endl; }