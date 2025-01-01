#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
  std::cout << "Creation of FragTrap " << name
            << ". La glorieuse evolution est en marche" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) {
  *this = other;
  std::cout << "Creation of FragTrap " << this->_name
            << ". La glorieuse evolution est en marche" << std::endl;
}

FragTrap::~FragTrap() {
  this->_life = 100;
  this->_energy = 100;
  this->_attack = 30;
  std::cout << "Destruction of FragTrap " << this->_name
            << ". The end of glory.." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
  this->_attack = other._attack;
  this->_energy = other._energy;
  this->_life = other._life;
  this->_name = other._name;
  return *this;
}

void FragTrap::highFivesGuys() {
  std::cout << "FragTrap " << this->_name << " asks for a high five! ✋"
            << std::endl;
}