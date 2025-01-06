#include "Cat.hpp"
#include "Dog.hpp"

int main() {
  const int size = 6;
  Animal *animals[size];

  for (int i = 0; i < size / 2; i++) {
    animals[i] = new Dog();
  }
  for (int i = size / 2; i < size; i++) {
    animals[i] = new Cat();
  }

  std::cout << "\n--- Animals Making Sounds ---" << std::endl;
  for (int i = 0; i < size; i++) {
    animals[i]->makeSound();
  }

  std::cout << "\n--- Deleting Animals ---" << std::endl;
  for (int i = 0; i < size; i++) {
    delete animals[i];
  }

  Dog basic;
  { Dog tmp = basic; }
  std::cout << "My first idea is : " << basic.getBrainIdea(0) << std::endl;

  return 0;
}
