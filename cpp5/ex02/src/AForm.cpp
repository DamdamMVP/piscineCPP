#include "AForm.hpp"

AForm::AForm()
    : _name("Unknow"), _isSigned(false), _gradeToSign(150),
      _gradeToExecute(150) {}

AForm::AForm(const std::string &name, int toSign, int toExec)
    : _name(name), _isSigned(false), _gradeToSign(toSign),
      _gradeToExecute(toExec) {
  if (_gradeToSign < 1 || _gradeToExecute < 1)
    throw GradeTooHighException();
  if (_gradeToSign > 150 || _gradeToExecute > 150)
    throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
    : _name(other._name), _isSigned(other._isSigned),
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &other) {
  if (this != &other) {
    this->_isSigned = other._isSigned;
  }
  return *this;
}

const std::string &AForm::getName() const { return _name; }

bool AForm::getIsSigned() const { return _isSigned; }
int AForm::getGradeToSign() const { return _gradeToSign; }
int AForm::getGradeToExec() const { return _gradeToExecute; }

const char *AForm::GradeTooHighException::what() const throw() {
  return "Grade is too High !";
}

const char *AForm::GradeTooLowException::what() const throw() {
  return "Grade is too Low !";
}

const char *AForm::FormNotSignedException::what() const throw() {
  return "Form is not Signed !";
}

void AForm::beSigned(const Bureaucrat &b) {
  if (b.getGrade() > _gradeToSign) {
    std::cout << b.getName() << " couldn't sign " << _name
              << " because grade is too low!" << std::endl;
    throw GradeTooLowException();
  }
  if (_isSigned) {
    std::cout << _name << " is already signed!" << std::endl;
    return;
  }
  std::cout << b.getName() << " signed " << _name << std::endl;
  _isSigned = true;
}

std::ostream &operator<<(std::ostream &out, const AForm &f) {
  out << f.getName() << ", form requires grade " << f.getGradeToSign()
      << " to sign and grade " << f.getGradeToExec() << " to execute."
      << "Currently " << (f.getIsSigned() ? "signed" : "not signed") << ".";
  return out;
}