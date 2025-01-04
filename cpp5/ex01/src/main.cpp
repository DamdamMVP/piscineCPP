#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
  Bureaucrat highRank("Alice", 10);
  Bureaucrat lowRank("Bob", 150);
  Bureaucrat midRank("Charlie", 50);

  Form taxForm("Tax Declaration", 45, 30);
  Form shrubberyForm("Shrubbery", 140, 100);
  Form pardonForm("Presidential Pardon", 5, 1);

  std::cout << taxForm << std::endl;
  std::cout << shrubberyForm << std::endl;
  std::cout << pardonForm << std::endl;

  std::cout << "\n--- Test 1 : Signature réussie ---" << std::endl;
  try {
    highRank.signForm(taxForm);
  } catch (const std::exception &e) {
    std::cerr << "Exception attrapée : " << e.what() << std::endl;
  }
  std::cout << taxForm << std::endl;

  std::cout << "\n--- Test 2 : Échec de signature (grade trop bas) ---"
            << std::endl;
  try {
    lowRank.signForm(taxForm);
  } catch (const std::exception &e) {
    std::cerr << "Exception attrapée : " << e.what() << std::endl;
  }

  std::cout << "\n--- Test 3 : Formulaire déjà signé ---" << std::endl;
  try {
    highRank.signForm(taxForm);
  } catch (const std::exception &e) {
    std::cerr << "Exception attrapée : " << e.what() << std::endl;
  }

  std::cout << "\n--- Test 4 : Formulaire facile à signer ---" << std::endl;
  try {
    midRank.signForm(shrubberyForm);
  } catch (const std::exception &e) {
    std::cerr << "Exception attrapée : " << e.what() << std::endl;
  }

  std::cout << "\n--- Test 5 : Signature de formulaire difficile ---"
            << std::endl;
  try {
    midRank.signForm(pardonForm);
  } catch (const std::exception &e) {
    std::cerr << "Exception attrapée : " << e.what() << std::endl;
  }

  std::cout << "\n--- État Final des Formulaires ---" << std::endl;
  std::cout << taxForm << std::endl;
  std::cout << shrubberyForm << std::endl;
  std::cout << pardonForm << std::endl;

  return 0;
}
