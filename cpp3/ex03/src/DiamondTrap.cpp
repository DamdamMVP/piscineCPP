#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string &name)
    : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name),
      _name(name) {
  this->_life = FragTrap::_life;
  this->_energy = ScavTrap::_energy;
  this->_attack = FragTrap::_attack;
  std::cout << "DiamondTrap " << this->_name << " is created!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
    : ClapTrap(other), FragTrap(other), ScavTrap(other) {
  *this = other;
  std::cout << "Copy of DiamondTrap " << this->_name << " created!"
            << std::endl;
}

DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap " << this->_name << " is destroyed." << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
  if (this != &other) {
    this->_name = other._name;
    this->_life = other._life;
    this->_energy = other._energy;
    this->_attack = other._attack;
  }
  return *this;
}

void DiamondTrap::whoAmI() {
  std::cout << "DiamondTrap name: " << this->_name
            << ", ClapTrap name: " << ClapTrap::_name << std::endl;
}
