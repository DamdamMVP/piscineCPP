#include "Bureaucrat.hpp"

int main() {
  Bureaucrat me("Damdam", 2);
  try {
    std::cout << me << std::endl;
    me.incrementGrade();
    std::cout << me << std::endl;
    me.incrementGrade();
    me.incrementGrade();
    me.incrementGrade();
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  std::cout << me << std::endl;
  return 0;
}