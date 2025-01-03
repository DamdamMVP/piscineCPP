#include "Brain.hpp"

Brain::Brain() {
  for (int i = 0; i < 100; i++) {
    ideas[i] = "nothing";
  }
  std::cout << "Brain created with default ideas set to 'nothing'" << std::endl;
}

Brain::Brain(const Brain &other) {
  for (int i = 0; i < 100; i++) {
    ideas[i] = other.ideas[i];
  }
  std::cout << "Brain created from copy" << std::endl;
}

Brain &Brain::operator=(const Brain &other) {
  if (this != &other) {
    for (int i = 0; i < 100; i++) {
      this->setIdea(i, other.getIdea(i));
    }
  }
  std::cout << "Brain assigned by operator=" << std::endl;
  return *this;
}

Brain::~Brain() { std::cout << "Brain destroyed" << std::endl; }

void Brain::setIdea(int index, const std::string &idea) {
  if (index >= 0 && index < 100) {
    this->ideas[index] = idea;
  }
}
std::string Brain::getIdea(int index) const {
  if (index >= 0 && index < 100) {
    return this->ideas[index];
  }
  return "Invalid index: out of range";
}