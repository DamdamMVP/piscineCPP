#include "ClapTrap.hpp"

int main() {
  ClapTrap Roger("Roger");
  ClapTrap Hubert("Hubert");

  Roger.attack("Hubert");
  Hubert.takeDamage(1);
  Roger.beRepaired(5);
  Hubert.attack("Roger");
  Roger.takeDamage(5);
  Roger.takeDamage(5);

  return 0;
}