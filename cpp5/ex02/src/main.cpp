#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main() {
  // Création des bureaucrates avec différents grades
  Bureaucrat president("President", 1);
  Bureaucrat manager("Manager", 50);
  Bureaucrat intern("Intern", 150);

  // Création des formulaires
  ShrubberyCreationForm shrub("Garden");
  RobotomyRequestForm robot("Bender");
  PresidentialPardonForm pardon("Arthur Dent");

  std::cout << shrub << std::endl;
  std::cout << robot << std::endl;
  std::cout << pardon << std::endl;

  // Test 1 : Tentative de signature par un intern (échec)
  std::cout << "\n--- Test 1 : Signature échouée (Intern trop bas) ---"
            << std::endl;
  try {
    intern.signForm(shrub);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  // Test 2 : Signature réussie par le manager
  std::cout << "\n--- Test 2 : Signature réussie (Manager) ---" << std::endl;
  try {
    manager.signForm(shrub);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  // Test 3 : Exécution réussie du formulaire Shrubbery par le manager
  std::cout << "\n--- Test 3 : Exécution (Manager) ---" << std::endl;
  try {
    manager.executeForm(shrub);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  // Test 4 : Signature du formulaire de robotomisation par le manager
  std::cout << "\n--- Test 4 : Signature RobotomyRequestForm ---" << std::endl;
  try {
    manager.signForm(robot);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  // Test 5 : Exécution du formulaire de robotomisation (50% de succès)
  std::cout << "\n--- Test 5 : Exécution RobotomyRequestForm ---" << std::endl;
  try {
    manager.executeForm(robot);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  // Test 6 : Signature et exécution par le président
  std::cout << "\n--- Test 6 : Signature et exécution par le Président ---"
            << std::endl;
  try {
    president.signForm(pardon);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    president.executeForm(pardon);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  // Test 7 : Tentative d'exécution par un intern (échec)
  std::cout << "\n--- Test 7 : Exécution échouée (Intern trop bas) ---"
            << std::endl;
  try {
    intern.executeForm(shrub);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
