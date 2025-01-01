#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Roger"), _life(10), _energy(10), _attack(0) {
  std::cout << "Creation of " << _name << std::endl;
}

ClapTrap::ClapTrap(const std::string name)
    : _name(name), _life(10), _energy(10), _attack(0) {
  std::cout << "Creation of " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
    : _name(other._name), _life(other._life), _energy(other._energy),
      _attack(other._attack) {
  std::cout << "Create the copy of " << _name << std::endl;
}

ClapTrap::~ClapTrap() { std::cout << "Destruction of " << _name << std::endl; }

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
  this->_attack = other._attack;
  this->_energy = other._energy;
  this->_life = other._life;
  this->_name = other._name;
  return *this;
}

void ClapTrap::attack(const std::string &target) {
  if (this->_energy == 0) {
    std::cout << "I have no more energy to attack !" << std::endl;
    return;
  }
  if (this->_life == 0) {
    std::cout << this->_name << " is actually dead..." << std::endl;
    return;
  }
  this->_energy--;
  std::cout << "ClapTrap " << this->_name << " attacks " << target
            << ", causing " << this->_attack << " points of damage !"
            << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (this->_life == 0) {
    std::cout << this->_name << " is actually dead..." << std::endl;
    return;
  }
  std::cout << this->_name << " take damage ! -" << amount << "HP" << std::endl;
  this->_life -= amount;
  this->actualStats();
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (this->_energy == 0) {
    std::cout << "I have no more energy to be repaired !" << std::endl;
    return;
  }
  if (this->_life == 0) {
    std::cout << this->_name << " is actually dead..." << std::endl;
    return;
  }
  this->_energy--;
  this->_life += amount;
  std::cout << "ClapTrap " << this->_name << " repaired himself ! Gain +"
            << amount << "HP." << std::endl;
  this->actualStats();
}

void ClapTrap::actualStats() {
  std::cout << this->_name << " -> HP[" << this->_life << "] | ENERGY["
            << this->_energy << "]" << std::endl;
}