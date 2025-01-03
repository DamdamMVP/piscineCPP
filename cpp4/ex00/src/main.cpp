#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
  const Animal *random = new Animal();
  const Animal *myDog = new Dog();
  const Animal *myCat = new Cat();

  std::cout << myDog->getType() << " " << std::endl;
  std::cout << myCat->getType() << " " << std::endl;
  myCat->makeSound();
  myDog->makeSound();
  random->makeSound();

  delete random;
  delete myDog;
  delete myCat;

  std::cout << "--- Testing WrongAnimal ---" << std::endl;
  const WrongAnimal *wrongRandom = new WrongAnimal();
  const WrongAnimal *wrongCat = new WrongCat();

  wrongCat->makeSound();
  wrongRandom->makeSound();

  delete wrongRandom;
  delete wrongCat;

  return 0;
}