#pragma once
#include "AForm.hpp"
#include <iostream>

class AForm;

class Bureaucrat {
private:
  const std::string _name;
  int _grade;

public:
  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw();
  };

  Bureaucrat();
  Bureaucrat(const std::string &name, int grade);
  Bureaucrat(const Bureaucrat &other);
  ~Bureaucrat();
  Bureaucrat &operator=(const Bureaucrat &other);

  const std::string &getName() const;
  int getGrade() const;

  void incrementGrade();
  void decrementGrade();
  void signForm(AForm &f);
  void executeForm(const AForm &form);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);