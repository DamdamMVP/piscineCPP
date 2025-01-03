#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include <iostream>

int main() {
  Character *player = new Character("Player");
  Character *enemy = new Character("Enemy");

  AMateria *ice = new Ice();
  AMateria *cure = new Cure();

  player->equip(ice);
  player->equip(cure);

  std::cout << "\n--- Testing Use ---" << std::endl;
  player->use(0, *enemy);
  player->use(1, *enemy);

  std::cout << "\n--- Cleaning Up ---" << std::endl;
  delete player;
  delete enemy;

  return 0;
}
