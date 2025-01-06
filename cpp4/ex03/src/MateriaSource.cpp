#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
  for (int i = 0; i < 4; i++)
    materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other) {
  for (int i = 0; i < 4; i++) {
    if (other.materias[i])
      materias[i] = other.materias[i]->clone();
    else
      materias[i] = NULL;
  }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
  if (this != &other) {
    for (int i = 0; i < 4; i++) {
      if (materias[i])
        delete materias[i];
      materias[i] = other.materias[i] ? other.materias[i]->clone() : NULL;
    }
  }
  return *this;
}

MateriaSource::~MateriaSource() {
  for (int i = 0; i < 4; i++) {
    if (materias[i])
      delete materias[i];
  }
}

void MateriaSource::learnMateria(AMateria *m) {
  for (int i = 0; i < 4; i++) {
    if (!materias[i]) {
      materias[i] = m;
      std::cout << "Materia learned: " << m->getType() << std::endl;
      return;
    }
  }
  delete m;
  return;
}

AMateria *MateriaSource::createMateria(std::string const &type) {
  for (int i = 0; i < 4; i++) {
    if (materias[i] && materias[i]->getType() == type)
      return materias[i]->clone();
  }
  std::cout << "Materia of type " << type << " not found!" << std::endl;
  return NULL;
}