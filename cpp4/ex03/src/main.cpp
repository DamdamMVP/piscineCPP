#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <iostream>

void testMateriaLearning() {
  std::cout << "\n--- Testing MateriaSource Learning ---" << std::endl;
  MateriaSource src;
  src.learnMateria(new Ice());
  src.learnMateria(new Cure());
  src.learnMateria(new Ice());
  src.learnMateria(new Cure());
  src.learnMateria(new Ice()); // Should not add (inventory full)
}

void testCharacterEquip() {
  std::cout << "\n--- Testing Character Equip and Use ---" << std::endl;
  MateriaSource src;
  src.learnMateria(new Ice());
  src.learnMateria(new Cure());

  Character player("Player");
  Character enemy("Enemy");

  AMateria *ice = src.createMateria("ice");
  AMateria *cure = src.createMateria("cure");

  player.equip(ice);
  player.equip(cure);

  player.use(0, enemy);
  player.use(1, enemy);
}

void testInventoryManagement() {
  std::cout << "\n--- Testing Inventory Management ---" << std::endl;
  Character player("Player");
  AMateria *ice1 = new Ice();
  AMateria *ice2 = new Ice();
  AMateria *cure = new Cure();

  player.equip(ice1);
  player.equip(ice2);
  player.equip(cure);
  player.equip(new Cure());
  player.equip(new Ice()); // Should not equip (inventory full)

  player.use(0, player);
  player.use(1, player);

  std::cout << "Unequipping slot 1" << std::endl;
  AMateria *unequipped = ice2;
  player.unequip(1);
  delete unequipped;
  player.use(1, player); // Should not do anything
}

void testDeepCopy() {
  std::cout << "\n--- Testing Deep Copy ---" << std::endl;
  Character player("Player");
  AMateria *ice = new Ice();
  player.equip(ice);

  Character clone(player);
  clone.use(0, clone);

  player.use(0, player); // Ensure player still owns its own materia
}

int main() {
  testMateriaLearning();
  testCharacterEquip();
  testInventoryManagement();
  testDeepCopy();

  std::cout << "\n--- All tests completed successfully! ---" << std::endl;
  return 0;
}
