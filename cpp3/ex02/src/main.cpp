#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
  FragTrap Terminator("Terminator");
  FragTrap Destroyer("Destroyer");

  Terminator.attack("Destroyer");
  Destroyer.takeDamage(30);
  Destroyer.highFivesGuys();

  return 0;
}
