#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("Shrubbery Creation", 145, 137), _target("Unknown") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("Shrubbery Creation", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), _target(other._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
  if (this != &other) {
    AForm::operator=(other);
    _target = other._target;
  }
  return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  if (!getIsSigned()) {
    throw FormNotSignedException();
  }
  if (executor.getGrade() > getGradeToExec()) {
    throw GradeTooLowException();
  }
  std::ofstream file((_target + "_shrubbery").c_str());
  if (!file.is_open()) {
    std::cerr << "Error: Couldn't open file." << std::endl;
    return;
  }

  file << "       ###" << std::endl;
  file << "      #o###" << std::endl;
  file << "    #####o###" << std::endl;
  file << "   #o#\\#|#/###" << std::endl;
  file << "    ###\\|/#o#" << std::endl;
  file << "     # }|{  #" << std::endl;
  file << "       }|{" << std::endl;
  file << std::endl;
  file << "       ###" << std::endl;
  file << "      #o###" << std::endl;
  file << "    #####o###" << std::endl;
  file << "   #o#\\#|#/###" << std::endl;
  file << "    ###\\|/#o#" << std::endl;
  file << "     # }|{  #" << std::endl;
  file << "       }|{" << std::endl;

  file.close();
  std::cout << "Shrubbery created at " << _target << "_shrubbery." << std::endl;
}
