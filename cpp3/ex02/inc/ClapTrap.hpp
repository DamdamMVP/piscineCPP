#pragma once
#include <iostream>

class ClapTrap {
protected:
  std::string _name;
  int _life;
  int _energy;
  int _attack;

public:
  ClapTrap();
  ClapTrap(const std::string name);
  ClapTrap(const ClapTrap &other);
  ~ClapTrap();
  ClapTrap &operator=(const ClapTrap &other);
  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
  void actualStats();
};