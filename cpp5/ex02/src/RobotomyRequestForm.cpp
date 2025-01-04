#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Robotomy Request", 72, 45), _target("Unknown") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("Robotomy Request", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), _target(other._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
  if (this != &other) {
    AForm::operator=(other);
    _target = other._target;
  }
  return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  if (!getIsSigned()) {
    throw FormNotSignedException();
  }
  if (executor.getGrade() > getGradeToExec()) {
    throw GradeTooLowException();
  }
  std::cout << "* BZZZZZT * Drilling noises..." << std::endl;
  std::srand(std::time(NULL)); // Initialisation de la seed
  if (std::rand() % 2 == 0) {
    std::cout << _target << " has been successfully robotomized!" << std::endl;
  } else {
    std::cout << "Robotomy failed on " << _target << "." << std::endl;
  }
}
