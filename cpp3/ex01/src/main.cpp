#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
  ScavTrap Hugue("Hugue");
  ScavTrap Albili("Albili");

  Hugue.attack("Albili");
  Albili.takeDamage(50);
  Albili.takeDamage(49);
  Albili.takeDamage(50);
  Albili.takeDamage(50);
  Albili.guardGate();
  return 0;
}