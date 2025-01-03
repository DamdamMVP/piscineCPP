#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
  Bureaucrat me("Damdam", 50);
  Form myForm("poser_perco", 48, 45);
  try {
	std::cout << myForm << std::endl;
    std::cout << me << std::endl;
    me.incrementGrade();
    std::cout << me << std::endl;
    myForm.beSigned(me);
    std::cout << "getIsSigned : " << myForm.getIsSigned() << std::endl;
    me.incrementGrade();
    std::cout << me << std::endl;
    myForm.beSigned(me);
    std::cout << "getIsSigned : " << myForm.getIsSigned() << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}