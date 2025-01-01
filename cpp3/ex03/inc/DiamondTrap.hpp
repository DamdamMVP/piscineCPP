#pragma once
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
private:
  std::string _name;

public:
  DiamondTrap(const std::string &name);
  DiamondTrap(const DiamondTrap &other);
  ~DiamondTrap();
  DiamondTrap &operator=(const DiamondTrap &other);

  void whoAmI();
  using ScavTrap::attack;
};