#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Unknown"), _grade(150) {}
Bureaucrat::Bureaucrat(const std::string &name, int grade)
    : _name(name), _grade(grade) {
  if (grade < 1)
    throw GradeTooHighException();
  if (grade > 150)
    throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : _name(other._name), _grade(other._grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
  if (this != &other) {
    this->_grade = other._grade;
  }
  return *this;
}

const std::string &Bureaucrat::getName() const { return _name; }
int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::incrementGrade() {
  if (_grade == 1)
    throw GradeTooHighException();
  _grade--;
}

void Bureaucrat::decrementGrade() {
  if (_grade == 150)
    throw GradeTooLowException();
  _grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade is too High !";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade is too Low !";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b) {
  out << b.getName() << ", bureaucrat grade " << b.getGrade();
  return out;
}