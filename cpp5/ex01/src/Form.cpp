#include "Form.hpp"

Form::Form()
    : _name("Unknow"), _isSigned(false), _gradeToSign(150),
      _gradeToExecute(150) {}

Form::Form(const std::string &name, int toSign, int toExec)
    : _name(name), _isSigned(false), _gradeToSign(toSign),
      _gradeToExecute(toExec) {
  if (_gradeToSign < 1 || _gradeToExecute < 1)
    throw GradeTooHighException();
  if (_gradeToSign > 150 || _gradeToExecute > 150)
    throw GradeTooLowException();
}

Form::Form(const Form &other)
    : _name(other._name), _isSigned(other._isSigned),
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
}

Form::~Form() {}

Form &Form::operator=(const Form &other) {
  if (this != &other) {
    this->_isSigned = other._isSigned;
  }
  return *this;
}

const std::string Form::getName() const { return _name; }

bool Form::getIsSigned() const { return _isSigned; }
int Form::gradeToSign() const { return _gradeToSign; }
int Form::gradeToExec() const { return _gradeToExecute; }

const char *Form::GradeTooHighException::what() const throw() {
  return "Grade is too High !";
}

const char *Form::GradeTooLowException::what() const throw() {
  return "Grade is too Low !";
}

void Form::beSigned(const Bureaucrat &b) {
  if (this->_gradeToSign < b.getGrade()) {
    std::cout << b.getName() << " couldn't sign " << _name
              << " because grade is too low !" << std::endl;
	throw GradeTooLowException();
  }
  std::cout << b.getName() << " signed " << _name << std::endl;
  this->_isSigned = true;
}

std::ostream &operator<<(std::ostream &out, const Form &f) {
  out << f.getName() << ", form requires grade " << f.gradeToSign()
      << " to sign and grade " << f.gradeToExec() << " to execute.";
  return out;
}