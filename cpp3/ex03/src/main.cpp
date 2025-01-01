#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
    DiamondTrap diamond("Legendary");

    diamond.attack("Target");
    diamond.whoAmI();

    return 0;
}

