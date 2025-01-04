#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}
Intern::Intern(const Intern &other) { (void)other; }
Intern::~Intern() {}
Intern &Intern::operator=(const Intern &other) {
  (void)other;
  return *this;
}

AForm *Intern::makeForm(const std::string &formName,
                        const std::string &target) {
  std::string tab[] = {"shrubbery creation", "robotomy request",
                       "presidential pardon"};
  int i;
  for (i = 0; i < 3; i++) {
    if (tab[i] == formName) {
      std::cout << "Intern creates " << formName << std::endl;
      break;
    }
  }

  switch (i) {
  case 0:
    return new ShrubberyCreationForm(target);
    break;
  case 1:
    return new RobotomyRequestForm(target);
    break;
  case 2:
    return new PresidentialPardonForm(target);
    break;
  default:
    std::cout << "Intern can't create " << formName
              << " because it doesn't exist !" << std::endl;
    return NULL;
    break;
  }
}