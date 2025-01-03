#pragma once
#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class Form {
private:
  const std::string _name;
  bool _isSigned;
  const int _gradeToSign;
  const int _gradeToExecute;

public:
  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw();
  };

  Form();
  Form(const std::string &name, int toSign, int toExec);
  Form(const Form &other);
  ~Form();
  Form &operator=(const Form &other);

  const std::string getName() const;
  bool getIsSigned() const;
  int gradeToSign() const;
  int gradeToExec() const;

  void beSigned(const Bureaucrat &b);
};

std::ostream &operator<<(std::ostream &out, const Form &f);