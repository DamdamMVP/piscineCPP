#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
  this->_life = 100;
  this->_energy = 50;
  this->_attack = 20;
  std::cout << "Creation of " << name << ", the ScavTrap original !"
            << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) {
  *this = other;
  std::cout << "Creation of " << other._name << ", the ScavTrap original !"
            << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
  this->_attack = other._attack;
  this->_energy = other._energy;
  this->_life = other._life;
  this->_name = other._name;
  std::cout << "Creation of " << this->_name
            << ", the ScavTrap original ! From operator=" << std::endl;
  return *this;
}

ScavTrap::~ScavTrap() {
  std::cout << "Destruction of " << this->_name << ", the original ScavTrap..."
            << std::endl;
}

void ScavTrap::attack(const std::string &target) {
  if (this->_energy <= 0) {
    std::cout << "I have no more energy to attack !" << std::endl;
    return;
  }
  if (this->_life <= 0) {
    std::cout << this->_name << " is actually dead..." << std::endl;
    return;
  }
  this->_energy--;
  std::cout << "ScavTrap " << this->_name << " attacks " << target
            << ", causing " << this->_attack << " points of damage ! GODNESS !"
            << std::endl;
}

void ScavTrap::guardGate(){
	std::cout << "Ptdr c'est moi le gardien ! Je m'appelle " << this->_name << std::endl;
}